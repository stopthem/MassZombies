// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveToPlayerProcessor.h"

#include "MassCommonFragments.h"
#include "MassCommonTypes.h"
#include "MassExecutionContext.h"
#include "MassNavigationFragments.h"
#include "Kismet/GameplayStatics.h"
#include "MassZombies/MASS/MoveToPlayer/Tags/MoveToPlayerTag.h"

UMoveToPlayerProcessor::UMoveToPlayerProcessor()
{
	// Automatically create a instance
	bAutoRegisterWithProcessingPhases = true;

	// Execute before avoidance because we have to set our goal before
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void UMoveToPlayerProcessor::ConfigureQueries()
{
	MassEntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadOnly);
	MassEntityQuery.AddRequirement<FMassMoveTargetFragment>(EMassFragmentAccess::ReadWrite);

	MassEntityQuery.AddTagRequirement<FMoveToPlayerTag>(EMassFragmentPresence::All);

	MassEntityQuery.RegisterWithProcessor(*this);
}

void UMoveToPlayerProcessor::Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context)
{
	FVector PlayerLocation = UGameplayStatics::GetPlayerPawn(Context.GetWorld(), 0)->GetActorLocation();

	MassEntityQuery.ForEachEntityChunk(EntityManager, Context, [&,PlayerLocation](FMassExecutionContext& MassExecutionContext)
	{
		const TConstArrayView<FTransformFragment> TransformList = MassExecutionContext.GetFragmentView<FTransformFragment>();
		const TArrayView<FMassMoveTargetFragment> MoveTargetList = MassExecutionContext.GetMutableFragmentView<FMassMoveTargetFragment>();

		for (int EntityIndex = 0; EntityIndex < MassExecutionContext.GetNumEntities(); ++EntityIndex)
		{
			const FVector EntityLocation = TransformList[EntityIndex].GetTransform().GetLocation();

			FMassMoveTargetFragment& MassMoveTargetFragment = MoveTargetList[EntityIndex];
			MassMoveTargetFragment.Center = PlayerLocation;
			MassMoveTargetFragment.Forward = (PlayerLocation - EntityLocation).GetSafeNormal();
		}
	});
}
