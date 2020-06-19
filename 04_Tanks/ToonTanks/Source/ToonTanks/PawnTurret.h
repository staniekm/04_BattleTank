

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.h"

#include "PawnTurret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()
	
public:

	APawnTurret();
	
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	
private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.0f;
	
	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;

	void CheckFireCondition();

	float ReturnDistanceToPlayer();
protected:
	
	
};
