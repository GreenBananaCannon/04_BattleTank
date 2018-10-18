// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-effect", is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}
}

// Get World location of linetrace through crosshair, true if hits lanscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY; // OUT parameters
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector CameraWorldLocation;
	FVector LookDirection;

	// "De-Project" the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace along the look direction, and see what we hit up to a max range
		// GetLookVectorHitLocation();
	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection  // OUT Parameter
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection) const
{
	//FHitResult OutHit;
	//FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	//FCollisionResponseParams ResponseParam;
	/*GetWorld()->LineTraceSingleByChannel
	(
		 OutHit,
		LookDirection,
		LookDirection + ,
		ECollisionChannel::ECC_Visibility,
		TraceParameters,
		ResponseParam
	);*/
	return false;
}