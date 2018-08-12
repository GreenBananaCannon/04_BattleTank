// Fill out your copyright notice in the Description page of Project SControlledTankettings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));

	auto AIControlledTank = GetAITank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *(AIControlledTank->GetName()));
	}

}

ATank * ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}