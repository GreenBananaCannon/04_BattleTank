// Fill out your copyright notice in the Description page of Project Settings.

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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;	

protected:
	UTankAimingComponent* AimingComponent = nullptr;

private:
	// How close the AI tank can get to the player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 3000;
	
};
