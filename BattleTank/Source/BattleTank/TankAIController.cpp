// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		// TODO Move towards the player

		// Aim towards the player
		
		ControlledTank->AimAt(PlayerTank->GetTargetLocation());

		ControlledTank->Fire(); // TODO Limit firing rate
	}

}

