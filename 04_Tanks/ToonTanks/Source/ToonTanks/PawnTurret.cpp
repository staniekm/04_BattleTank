


#include "PawnTurret.h"

APawnTurret::APawnTurret()
{
    
}

void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true, false);
}

void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}



void APawnTurret::CheckFireCondition()
{
   //TODO
        // if player == null || is dead then bail

        // if player is in range then fire

   
}


