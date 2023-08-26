// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"

#include "MSCollisionProcessors.generated.h"
/**
 * Queries the Mass Sample octree
 * 
 */
UCLASS()
class MASSCOMMUNITYSAMPLE_API UMSEntityCollisionQueryProcessors : public UMassProcessor
{
	GENERATED_BODY()

	UMSEntityCollisionQueryProcessors();

protected:
	virtual void ConfigureQueries() override;

	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

public:
	virtual void Initialize(UObject& Owner) override;

protected:
	// Yeah... I know
	FMassEntityQuery OctreeQueryQuery;

	UPROPERTY()
	class UMSSubsystem* MSSubsystem;;
};
