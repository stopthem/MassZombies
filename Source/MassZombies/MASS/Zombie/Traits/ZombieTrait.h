// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassZombies/MASS/Zombie/Killed/Fragments/ZombieKilledParams.h"

#include "ZombieTrait.generated.h"

/**
 * UZombieTrait
 *
 * Trait that all zombies has.
 */
UCLASS()
class MASSZOMBIES_API UZombieTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;

	UPROPERTY(Category="Killed", EditAnywhere)
	FZombieKilledParams ZombieKilledParams;
};
