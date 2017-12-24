// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"), *(ControlledTank->GetName()));
	}
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCorsshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCorsshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out paramter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *(HitLocation.ToString()));
	
		// TODO Tell conntroller to start moving parts to hit target
	}
}

//Get world location of linetrace through crosshair, trure if hits landscpe 
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *(ScreenLocation.ToString()));
	// "De-project" the screen position of the crosshair wo a world direction
	// Line-trace along that look direction, and see what we hit (up to some max value)
	return true;
}



