#pragma once
#include "MassEntityTypes.h"

#include "ZombieKilledParamsFragment.generated.h"

/*
 * FZombieKilledParams
 *
 * Struct that holds parameters about zombie killing
 */
USTRUCT()
struct FZombieKilledParamsFragment : public FMassSharedFragment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Particle")
	TObjectPtr<UParticleSystem> ParticleToPlayWhenKilled;

	UPROPERTY(EditAnywhere, Category="Particle")
	FVector ParticlePlayOffset = FVector(0, 0, 60.0f);
};
