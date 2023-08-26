// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "KillZombiesInBoxProcessor.generated.h"

/**
 * 
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
