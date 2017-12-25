// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Tank.h"


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAiController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAiController found player: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAiController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		//TODO move towards the player

		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());


		//Fire if ready
	}
}

ATank* ATankAiController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	
	return Cast<ATank>(PlayerTank);
}


