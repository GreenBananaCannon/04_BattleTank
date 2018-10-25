// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the turret the right amount this frame
	// given a max rotation speed, and the frame time
	
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRawRotation = RelativeRotation.Yaw + RotationChange;

	//FRotator(0, (TurretDeltaRotator.Yaw * GetWorld()->DeltaTimeSeconds) + Turret->RelativeRotation.Yaw, 0), false);
	SetRelativeRotation(FRotator(0,NewRawRotation,0));
}


