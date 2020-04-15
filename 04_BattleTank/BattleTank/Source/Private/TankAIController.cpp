// Marcin Staniek Game Dev Course 2020

#include "Tank.h"
#include "TankAIController.h"
// Depends on movement component via pathfinding syste

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    /* auto PlayerTank = GetPlayerTank();
    if (!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController cant find player tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
    } */
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());

    if (ensure(PlayerTank))
    {       
        //move towards player
        MoveToActor(PlayerTank, AcceptanceRadius); // todo check if radius in cm
        //Aim towards the player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        ControlledTank->Fire(); //TODO limit firing rate    
    }
    
}




