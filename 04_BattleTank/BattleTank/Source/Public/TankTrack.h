// Marcin Staniek Game Dev Course 2020
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving forcem abd aply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	// Sets throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	// Max force per track in N
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000; // asume 1g acceleration and 40t tank

private:
	UTankTrack();

	TArray<class ASprungWheel*> GetWheels() const;

	void DriveTrack(float CurrentThrottle);

};

//relative location for spawnpoint of sprungwheel but something FUCKED
//front left 320 20
//rear left -320 20
//front right 320 -20 or -260
//rear right -320 -20 or -260