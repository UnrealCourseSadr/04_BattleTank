// Copyright MSadrpour

#include "Tank.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("Finch C++: Constructor executed"))
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Finch C++: Begin Play executed"))
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (bIsReloaded)
	{
		/// Spawn a projectile at the socket location on the barrel
		FVector ProjectileLocation = Barrel->GetSocketLocation(FName("Projectile"));
		FRotator ProjectileRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ProjectileLocation, ProjectileRotation);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

	
}
