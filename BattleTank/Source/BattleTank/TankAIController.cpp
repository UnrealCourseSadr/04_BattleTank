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

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		ATank*  PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
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

	if (TankAimingComponent->GetFiringState() == EFiringState::Locked)
		TankAimingComponent->Fire(); // TODO Limit firing rate

}

void ATankAIController::OnPossessedTankDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("Received OnDeath"))
}

