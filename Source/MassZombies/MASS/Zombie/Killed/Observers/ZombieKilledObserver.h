// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassObserverProcessor.h"
#include "ZombieKilledObserver.generated.h"

/**
 * UZombieKilledObserver
 *
 * When a FKilledTag added to a Zombie, this processor kills them
 */
UCLASS()
class MASSZOMBIES_API UZombieKilledObserver : public UMassObserverProcessor
{
	GENERATED_BODY()

public:
	UZombieKilledObserver();

protected:
	virtual void ConfigureQueries() override;

	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

protected:
	FMassEntityQuery MassEntityQuery;
};
