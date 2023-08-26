#pragma once

#include "MassEntityTypes.h"

#include "KilledTag.generated.h"

/*
 * FKilledTag
 *
 * Tag that indicates a entity has ben manually marked to be killed.
 */
USTRUCT()
struct FKilledTag : public FMassTag
{
	GENERATED_BODY()
};
