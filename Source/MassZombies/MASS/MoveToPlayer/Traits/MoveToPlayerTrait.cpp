// Fill out your copyright notice in the Description page of Project Settings.

#include "MoveToPlayerTrait.h"

#include "MassCommonFragments.h"
#include "MassEntityTemplateRegistry.h"
#include "MassNavigationFragments.h"
#include "MassZombies/MASS/MoveToPlayer/Tags/MoveToPlayerTag.h"

void UMoveToPlayerTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const
{
	BuildContext.RequireFragment<FTransformFragment>();
	BuildContext.RequireFragment<FMassMoveTargetFragment>();

	BuildContext.AddTag<FMoveToPlayerTag>();
}
