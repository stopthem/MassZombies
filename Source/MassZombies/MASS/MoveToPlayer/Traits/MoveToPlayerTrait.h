// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"

#include "MoveToPlayerTrait.generated.h"

/**
 * UMoveToPlayerTrait
 *
 * Every entity that has to look and move towards player must have this trait.
 * Also handles necessary tag and fragments.
 */
UCLASS()
class MASSZOMBIES_API UMoveToPlayerTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;
};
