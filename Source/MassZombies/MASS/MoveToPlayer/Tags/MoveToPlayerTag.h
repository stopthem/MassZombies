#pragma once
#include "MassEntityTypes.h"

#include "MoveToPlayerTag.generated.h"

/*
 * FMoveToPlayerTag
 *
 * Tag that indicates a entity wants to move towards player.
 */
USTRUCT()
struct FMoveToPlayerTag : public FMassTag
{
	GENERATED_BODY()
};
