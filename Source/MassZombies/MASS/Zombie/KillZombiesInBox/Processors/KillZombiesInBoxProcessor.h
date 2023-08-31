// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "KillZombiesInBoxProcessor.generated.h"

/**
 * UKillZombiesInBoxProcessor
 *
 * Kills the zombies when they are in a box around player.
 */
UCLASS()
class MASSZOMBIES_API UKillZombiesInBoxProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:
	UKillZombiesInBoxProcessor();

protected:
	virtual void ConfigureQueries() override;

	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery MassEntityQuery;
};
