// Copyright GreenBananaCannon

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // put new includes above this

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate); // Create a delegate Observer

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	FTankDelegate OnDeath; // Event that to be observed by subscribed listeners

	// called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// returns current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health") //blueprintpure, makes this a readonly function, similar to const
	float GetHealthPercentage() const;

private:
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 CurrentHealth; // Initialized in BeginPlay()
};
