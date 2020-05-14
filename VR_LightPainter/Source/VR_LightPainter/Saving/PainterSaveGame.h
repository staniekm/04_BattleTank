

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PainterSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class VR_LIGHTPAINTER_API UPainterSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    static UPainterSaveGame* Create();
    bool Save();

    static UPainterSaveGame* Load();

    void SetState(FString NewState) { State = NewState; }
    FString GetState() const { return State; }

private:
    // State
    UPROPERTY()
    FString State;
};
