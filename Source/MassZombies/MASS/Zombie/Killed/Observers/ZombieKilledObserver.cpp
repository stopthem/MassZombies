// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieKilledObserver.h"

#include "MassCommonFragments.h"
#include "MassExecutionContext.h"
#include "Kismet/GameplayStatics.h"
#include "MassZombies/MASS/Zombie/Killed/Fragments/ZombieKilledParams.h"
#include "MassZombies/MASS/Zombie/Killed/Tags/KilledTag.h"
#include "MassZombies/MASS/Zombie/Tags/ZombieTag.h"

UZombieKilledObserver::UZombieKilledObserver()
{
	ObservedType = FKilledTag::StaticStruct();
	Operation = EMassObservedOperation::Add;
}

void UZombieKilledObserver::ConfigureQueries()
{
	MassEntityQuery.AddTagRequirement<FZombieTag>(EMassFragmentPresence::All);
	MassEntityQuery.AddTagRequirement<FKilledTag>(EMassFragmentPresence::All);

	MassEntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	MassEntityQuery.AddConstSharedRequirement<FZombieKilledParams>();

	MassEntityQuery.RegisterWithProcessor(*this);
}

void UZombieKilledObserver::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	// std::atomic is thread-safe and this processor probably use multithreading.
	std::atomic<int32> ToBeDestroyedEntities;
	
	MassEntityQuery.ForEachEntityChunk(EntityManager, Context, [&](FMassExecutionContext& MassExecutionContext)
	{
		const TConstArrayView<FTransformFragment> TransformsList = MassExecutionContext.GetFragmentView<FTransformFragment>();
		const FZombieKilledParams& ZombieKilledParams = MassExecutionContext.GetConstSharedFragment<FZombieKilledParams>();

		for (int EntityIndex = 0; EntityIndex < MassExecutionContext.GetNumEntities(); ++EntityIndex)
		{
			const FTransform EntityTransform = TransformsList[EntityIndex].GetTransform();
			const FVector ParticlePlayLocation = EntityTransform.GetLocation() + ZombieKilledParams.ParticlePlayOffset;

			UGameplayStatics::SpawnEmitterAtLocation(MassExecutionContext.GetWorld(), ZombieKilledParams.ParticleToPlayWhenKilled, ParticlePlayLocation);

			++ToBeDestroyedEntities;
		}
	});

	if (ToBeDestroyedEntities > 0)
	{
		Context.Defer().DestroyEntities(Context.GetEntities());
	}
}
