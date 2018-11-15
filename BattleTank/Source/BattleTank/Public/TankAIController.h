// Copyright GreenBananaCannon
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
// Depends on movement component via pathfinding system

class UTankAimingComponent;

/**
 * Tank AI controller for the enemy tanks.
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UTankAimingComponent* AimingComponent = nullptr;

	// How close the AI tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptanceRadius = 8000;

	UFUNCTION()
	void OnTankDeath();

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

};
