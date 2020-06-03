

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIGuard.generated.h"

class UPawnSensingComponent;

UCLASS()
class TL_STEALTHGAME_API AAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	AAIGuard();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UPawnSensingComponent* PawnSensingComp;
	
public:	
	virtual void Tick(float DeltaTime) override;

	
};
