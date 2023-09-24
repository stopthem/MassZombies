// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZombiesInBoxProcessor.h"

#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "MassRepresentationTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "MassZombies/MASS/Zombie/Killed/Tags/KilledTag.h"
#include "MassZombies/MASS/Zombie/Tags/ZombieTag.h"

UKillZombiesInBoxProcessor::UKillZombiesInBoxProcessor()
{
	// Automatically create a instance
	bAutoRegisterWithProcessingPhases = true;
	
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Movement);
}

void UKillZombiesInBoxProcessor::ConfigureQueries()
{
	MassEntityQuery.AddTagRequirement<FZombieTag>(EMassFragmentPresence::All);
	// We can iterate through entities that has the tag so avoid that with this requirement
	MassEntityQuery.AddTagRequirement<FKilledTag>(EMassFragmentPresence::None);

	MassEntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);

	MassEntityQuery.RegisterWithProcessor(*this);
}

void UKillZombiesInBoxProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	const APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(Context.GetWorld(), 0);
	FVector PlayerLocation = PlayerPawn->GetActorLocation() + PlayerPawn->GetActorForwardVector() * 100.0f;

	MassEntityQuery.ForEachEntityChunk(EntityManager, Context, [PlayerLocation](const FMassExecutionContext& MassExecutionContext)
	{
		const TConstArrayView<FTransformFragment> TransformFragmentsList = MassExecutionContext.GetFragmentView<FTransformFragment>();

		for (int EntityIndex = 0; EntityIndex < MassExecutionContext.GetNumEntities(); ++EntityIndex)
		{
			// Get zombie location
			const FVector EntityLocation = TransformFragmentsList[EntityIndex].GetTransform().GetLocation();

			// Is zombie location inside our box?
			if (UKismetMathLibrary::IsPointInBox(EntityLocation, PlayerLocation, FVector(200.0f, 200.0f, 100.0f)))
			{
				// It is important that we use Defer() because it notifies UMassObserverProcessor's that a tag is added to entity.
				MassExecutionContext.Defer().AddTag<FKilledTag>(MassExecutionContext.GetEntity(EntityIndex));
			}
		}
	});
}
