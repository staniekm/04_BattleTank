

#include "Gun.h"

#include "Components/SkeletalMeshComponent.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);	

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{
	UE_LOG(LogTemp,Warning,TEXT("SHOT"));
}

void AGun::BeginPlay()
{
	Super::BeginPlay();

}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

