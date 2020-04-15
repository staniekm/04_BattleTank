// Marcin Staniek Game Dev Course 2020

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override; //something with inheritance

	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadius = 3000;
};
