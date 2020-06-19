


#include "TankGameModeBase.h"


#include "Kismet/GameplayStatics.h"
#include "ToonTanks/PawnTurret.h"

void ATankGameModeBase::BeginPlay()
{
    // Get references and game win/lose conditions.

    // Call HandleGameStart to initialise the start countdown, turret activation, pawn check etc.

    TargetTurrets = GetTargetTurrets();

    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

    HandleGameStart();
    
    Super::BeginPlay();
}

int32 ATankGameModeBase::GetTargetTurrets()
{
    TSubclassOf<APawnTurret> ClassToFind;
    ClassToFind = APawnTurret::StaticClass();
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, TurretActors);

    return TurretActors.Num();
}

void ATankGameModeBase::ActorDied(AActor *DeadActor)
{
	// UE_LOG(LogTemp, Warning, TEXT("An Actor died"));

    if (DeadActor == PlayerTank)
    {
        PlayerTank->PawnDestroyed();
        HandleGameOver(false);
    }
    else if (APawnTurret* DestroyedTurret = Cast<APawnTurret>(DeadActor))
    {
        DestroyedTurret->PawnDestroyed();

        TargetTurrets--;

        if (TargetTurrets == 0)
        {
            HandleGameOver(true);
        }
    }
}



void ATankGameModeBase::HandleGameStart()
{
   GameStart();
} 

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
    GameOver(PlayerWon);
}

