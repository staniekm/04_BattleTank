


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (PlayerPawn == nullptr) return;
    
    if (LineOfSightTo(PlayerPawn))
    {
        SetFocus(PlayerPawn);
        MoveToActor(PlayerPawn, AcceptanceRadius);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }

    // TODO turn off focus when AI is dead
}

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

}
