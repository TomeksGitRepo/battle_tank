// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"

//* Depends on movement component via pathfinding system

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm
		//Aim towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if(AimingComponent->GetFiringState() == EFiringState::Locked)
		{
			AimingComponent->Fire(); //TODO limit firing rate
		}
			
}





