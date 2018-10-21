// Fill out your copyright notice in the Description page of Project SControlledTankettings.

#include "Tank.h"
#include "TankAIController.h"
#include "Engine/World.h"




void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AIPawn = GetAITank();
	if (AIPawn) 
	{ 
		AIPawn->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));

	auto PlayerControlledTank = GetPlayerTank();
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController didn't find the player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found Player Tank: %s"), *(PlayerControlledTank->GetName()));
	}

}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
