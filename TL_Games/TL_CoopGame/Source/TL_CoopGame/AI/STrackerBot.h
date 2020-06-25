

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Sound/SoundCue.h"
#include "TL_CoopGame/Components/SHealthComponent.h"

#include "STrackerBot.generated.h"

UCLASS()
class TL_COOPGAME_API ASTrackerBot : public APawn
{
	GENERATED_BODY()

public:
	ASTrackerBot();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category="Coponents")
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleDefaultsOnly, Category="Coponents")
	USHealthComponent* HealthComp;

	UPROPERTY(VisibleDefaultsOnly, Category="Coponents")
	USphereComponent* SphereComp;

	UFUNCTION()
	void HandleTakeDamage(USHealthComponent* OwningHealthComp, float Health, float HealthDelta,
	const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	FVector GetNextPathPoint();

	FVector NexTPathPoint;

	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	float MovementForce;

	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	bool bUseVelocityChange;
	
	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	float RequiredDistanceToTarget;

	UMaterialInstanceDynamic* MatInst;

	void SelfDestruct();

	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	UParticleSystem* ExplosionEffect;

	bool bExploded;

	bool bStartedSelfDestruction;
	
	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	float ExplosionRadius;
	
	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	float ExplosionDamage;

	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	float SelfDamageInterval;
	
	FTimerHandle TimerHandle_SelfDamage;

	void DamageSelf();

	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
	USoundCue* SelfDestructSound;

	UPROPERTY(EditDefaultsOnly, Category="TracketBot")
    USoundCue* ExplodeSound;

	
	
public:	
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
