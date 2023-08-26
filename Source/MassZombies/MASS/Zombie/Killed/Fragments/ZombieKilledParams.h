#pragma once
#include "MassEntityTypes.h"

#include "ZombieKilledParams.generated.h"

/*
 * FZombieKilledParams
 *
 * Struct that holds parameters about zombie killing
 */
USTRUCT()
struct FZombieKilledParams : public FMassSharedFragment
{
	GENERATED_BODY()

public:
	UPROPERTY(Category="Particle", EditAnywhere)
	TObjectPtr<UParticleSystem> ParticleToPlayWhenKilled;

	UPROPERTY(Category="Particle", EditAnywhere)
	FVector ParticlePlayOffset = FVector(0, 0, 60.0f);
};
