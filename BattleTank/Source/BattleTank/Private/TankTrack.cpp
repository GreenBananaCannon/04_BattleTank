// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto TrackVelocity = GetComponentVelocity();
	auto TrackRightVector = GetRightVector().GetSafeNormal();
	auto SlippageSpeed = FVector::DotProduct(TrackRightVector, TrackVelocity);

	//work out the required acceleration this frame to correct
	//apply force in the opposite direction that we are slipping
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * TrackRightVector;
	// calculate  and apply sidways force F = m * a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // two tracks 
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}