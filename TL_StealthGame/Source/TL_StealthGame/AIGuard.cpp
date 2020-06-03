


#include "AIGuard.h"
#include "Perception/PawnSensingComponent.h"

AAIGuard::AAIGuard()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	
}

void AAIGuard::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIGuard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



