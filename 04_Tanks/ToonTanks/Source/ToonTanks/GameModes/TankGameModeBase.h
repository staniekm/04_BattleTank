

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanks/PawnTank.h"

#include "TankGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

    virtual void BeginPlay() override;

public:

    void ActorDied(AActor* DeadActor);

    UFUNCTION(BlueprintImplementableEvent)
    void GameStart();
 
    UFUNCTION(BlueprintImplementableEvent)
    void GameOver(bool PlayerWon);

    
private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameLoop",  meta = (AllowPrivateAccess = "true"))
    int StartDelay = 3;
    
    int32 TargetTurrets = 0;
    int32 GetTargetTurrets();
    
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Player",  meta = (AllowPrivateAccess = "true"))
    APawnTank* PlayerTank;

    
    void HandleGameStart();
    void HandleGameOver(bool PlayerWon);
};
