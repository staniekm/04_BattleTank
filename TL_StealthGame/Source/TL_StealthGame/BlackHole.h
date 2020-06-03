

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "BlackHole.generated.h"

UCLASS()
class TL_STEALTHGAME_API ABlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlackHole();

	protected:

        UPROPERTY(VisibleAnywhere, Category = "Components")
        UStaticMeshComponent* MeshComp;

	/* Inner sphere destroys the overlapping components */
	UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent* InnerSphereComponent;

	/* Outer sphere pulls components (that are physically simulating) towards the centre of the actor */
	UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent* OuterSphereComponent;

	// Marked with ufunction to bind to overlap event
	UFUNCTION()
    void OverlapInnerSphere(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	public:	
        // Called every frame
        virtual void Tick(float DeltaTime) override;


};
