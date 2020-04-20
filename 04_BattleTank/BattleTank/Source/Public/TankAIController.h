// Marcin Staniek Game Dev Course 2020

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 3000;

private:
	virtual void SetPawn(APawn* InPawn) override;

	virtual void BeginPlay() override; 

	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnPossedTankDeath();
};
