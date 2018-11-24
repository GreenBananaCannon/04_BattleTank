// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> TankTrackWheels;
	TArray<USceneComponent*> TankTrackSpawnPoints;
	GetChildrenComponents(false, TankTrackSpawnPoints); // populate out TArray with tank track children

	for (auto Child : TankTrackSpawnPoints)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		auto SprungWheel = Cast<ASprungWheel>(SpawnPointChild->GetSpawnedActor());
		if (!SprungWheel) continue;
		TankTrackWheels.Add(SprungWheel);
	}
	return TankTrackWheels;
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num(); // two wheels per track
	for (ASprungWheel* Wheel : Wheels)
	{
		if (!Wheel) { return; }
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}