
#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "ObjectiveActor.generated.h"

UCLASS()
class TL_STEALTHGAME_API AObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AObjectiveActor();

protected:
	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, Category="FX")
	UParticleSystem* PickupFX;
	
	virtual void BeginPlay() override;

	void PlayEffects();

public:	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
