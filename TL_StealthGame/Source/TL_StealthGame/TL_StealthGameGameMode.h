// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TL_StealthGameGameMode.generated.h"

UCLASS(minimalapi)
class ATL_StealthGameGameMode : public AGameModeBase
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditDefaultsOnly, Category="Spectating")
	TSubclassOf<AActor> SpectatingViewpointClass;
public:
	ATL_StealthGameGameMode();

	void CompleteMission(APawn* InstagatorPawn);

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void OnMissionCompleted(APawn* InstagatorPawn);
};



