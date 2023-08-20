// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MoveToPlayerProcessor.generated.h"

/**
 * UMoveToPlayerProcessor
 *
 * Handles all entities that trying to move towards player.
 */
UCLASS()
class MASSZOMBIES_API UMoveToPlayerProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UMoveToPlayerProcessor();

protected:
	// Filter which entities we want to handle
	virtual void ConfigureQueries() override;

	// Iterate through our entities
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	// The filter that we select our entities from
	FMassEntityQuery MassEntityQuery;
};
