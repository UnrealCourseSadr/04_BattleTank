// Copyright MSadrpour

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// TODO Remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.f; 

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	FTankDelegate OnDeath;

	// Returns current health as a percentage of starting health between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;
};
