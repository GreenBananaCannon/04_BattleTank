// Fill out your copyright notice in the Description page of Project SControlledTankettings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("IM here"))
	auto AimingComponent = FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AITank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!ensure(PlayerTank && AITank)) { return; }
	
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius, true, true, false); //TODO check radius is in cm
	
		
	// Aim towards the player
	auto AimingComponent = FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//TODO fix firing
	//AITank->Fire();
}
