// Copyright MSadrpour

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}