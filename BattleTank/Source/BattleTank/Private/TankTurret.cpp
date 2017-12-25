// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Tank.h"
#include "TankAimingComponent.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	//Move the Turret the right amount this frame
	//Given a max elevation speed, and frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange; 

	SetRelativeRotation(FRotator(0, Rotation, 0));
}



