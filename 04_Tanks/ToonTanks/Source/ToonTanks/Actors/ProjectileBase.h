

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "ProjectileBase.generated.h"

UCLASS()
class TOONTANKS_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectileBase();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta = (AllowPrivateAccess = "true"))
	float MovementSpeed = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage", meta = (AllowPrivateAccess = "true"))
	float Damage = 50.0f;

	

protected:
	virtual void BeginPlay() override;

};
