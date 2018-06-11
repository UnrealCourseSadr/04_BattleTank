// Copyright MSadrpour

#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/Controller.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(PlayerTank && TankAimingComponent)) { return; }
	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check radius is in CMs

	// Aim towards the player
	TankAimingComponent->AimAt(PlayerTank->GetTargetLocation());

	TankAimingComponent->Fire(); // TODO Limit firing rate

}

