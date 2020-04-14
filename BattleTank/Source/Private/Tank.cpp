// Marcin Staniek Game Dev Course 2020

//#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: DONKEY: Tank C++ Construct"), *TankName);
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); //Needed for BP Begin Play to run
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: DONKEY: Tank C++ Tank C++ Begin Play"), *TankName);
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent)
	{
		return;
	}
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Tank fires "));
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (Barrel && isReloaded)
	{
		//Spawn a projectile at a socket Location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))

		);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}
