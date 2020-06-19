


#include "PawnTurret.h"

#include "Kismet/GameplayStatics.h"

APawnTurret::APawnTurret()
{
    
}

void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true, false);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    CheckFireCondition();
}



void APawnTurret::CheckFireCondition()
{
   //TODO
        // if player == null || is dead then bail
   if (!PlayerPawn)
   {
       return;
   }
        // if player is in range then fire
   if (ReturnDistanceToPlayer() <= FireRange)
   {
       // Fire

       UE_LOG(LogTemp,Warning,TEXT("FIRE"));
   }
   
}

float APawnTurret::ReturnDistanceToPlayer()
{
    // Check if we have a valid reference to the player
    if (!PlayerPawn)
    {
        return 0.0f;
    }

    float Distance = (PlayerPawn->GetActorLocation() - GetActorLocation()).Size();
    return Distance;
}


