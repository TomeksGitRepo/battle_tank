// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class ATank; //Forward declaration

UCLASS()
class BATTLETANK_API ATankAiController : public AAIController
{
	GENERATED_BODY()
	
private:
	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	

	//How close can the AI tank get to target
	float AcceptanceRadius = 3000;
	
};
