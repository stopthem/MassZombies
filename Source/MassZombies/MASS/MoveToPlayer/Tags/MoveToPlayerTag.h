#pragma once
#include "MassEntityTypes.h"

#include "MoveToPlayerTag.generated.h"

/*
 * FMoveToPlayerTag
 *
 * MoveToPlayerProcessor uses this tag to filter its entities.
 */
USTRUCT()
struct FMoveToPlayerTag : public FMassTag
{
	GENERATED_BODY()
};
