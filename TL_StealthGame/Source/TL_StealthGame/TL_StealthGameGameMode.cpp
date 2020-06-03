// Copyright Epic Games, Inc. All Rights Reserved.

#include "TL_StealthGameGameMode.h"
#include "TL_StealthGameHUD.h"
#include "TL_StealthGameCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ATL_StealthGameGameMode::ATL_StealthGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATL_StealthGameHUD::StaticClass();
}

void ATL_StealthGameGameMode::CompleteMission(APawn* InstagatorPawn)
{
	if (InstagatorPawn)
	{
		UE_LOG(LogTemp, Log, TEXT("Input Disabled"));
		InstagatorPawn->DisableInput(nullptr);

		if (SpectatingViewpointClass)
		{
			TArray<AActor*> ReturnedActors;
			UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewpointClass, ReturnedActors);
			if (ReturnedActors.Num() > 0)
			{
				AActor* NewViewTarget = ReturnedActors[0];

				APlayerController* PC = Cast<APlayerController>(InstagatorPawn->GetController());
				if (PC)
				{
					PC->SetViewTargetWithBlend(NewViewTarget, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("There is no actor to set new viewport"))
		}
	}
	
	OnMissionCompleted(InstagatorPawn);
	
}
