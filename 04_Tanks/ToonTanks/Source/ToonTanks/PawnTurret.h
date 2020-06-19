

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
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
	
	void CheckFireCondition();
	FTimerHandle FireRateTimerHandle;

	
protected:
	
	
};
