// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieKilledObserver.h"

#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "Kismet/GameplayStatics.h"
#include "MassZombies/MASS/Zombie/Killed/Fragments/ZombieKilledParamsFragment.h"
#include "MassZombies/MASS/Zombie/Killed/Tags/KilledTag.h"
#include "MassZombies/MASS/Zombie/Tags/ZombieTag.h"

UZombieKilledObserver::UZombieKilledObserver()
{
	ObservedType = FKilledTag::StaticStruct();
	// Observe when the tag is Added
	Operation = EMassObservedOperation::Add;

	ExecutionOrder.ExecuteAfter.Add(UE::Mass::ProcessorGroupNames::Movement);
}

void UZombieKilledObserver::ConfigureQueries()
{
	MassEntityQuery.AddTagRequirement<FZombieTag>(EMassFragmentPresence::All);
	// We have to add a requirement to the tag we are observing. Otherwise our query will be empty
	MassEntityQuery.AddTagRequirement<FKilledTag>(EMassFragmentPresence::All);

	MassEntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	MassEntityQuery.AddConstSharedRequirement<FZombieKilledParamsFragment>();

	MassEntityQuery.RegisterWithProcessor(*this);
}

void UZombieKilledObserver::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	MassEntityQuery.ForEachEntityChunk(EntityManager, Context, [&](FMassExecutionContext& MassExecutionContext)
	{
		const TConstArrayView<FTransformFragment> TransformsList = MassExecutionContext.GetFragmentView<FTransformFragment>();
		const FZombieKilledParamsFragment& ZombieKilledParams = MassExecutionContext.GetConstSharedFragment<FZombieKilledParamsFragment>();

		for (int EntityIndex = 0; EntityIndex < MassExecutionContext.GetNumEntities(); ++EntityIndex)
		{
			const FTransform EntityTransform = TransformsList[EntityIndex].GetTransform();

			// Spawn death vfx
			const FVector ParticlePlayLocation = EntityTransform.GetLocation() + ZombieKilledParams.ParticlePlayOffset;
			UGameplayStatics::SpawnEmitterAtLocation(MassExecutionContext.GetWorld(), ZombieKilledParams.ParticleToPlayWhenKilled, ParticlePlayLocation);
		}
	});

	Context.Defer().DestroyEntities(Context.GetEntities());
}
