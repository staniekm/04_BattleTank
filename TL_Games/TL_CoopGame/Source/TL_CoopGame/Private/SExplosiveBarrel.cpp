


#include "SExplosiveBarrel.h"
#include "TL_CoopGame/Components/SHealthComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Kismet/GameplayStatics.h"

ASExplosiveBarrel::ASExplosiveBarrel()
{
    HealthComp = CreateDefaultSubobject<USHealthComponent>(TEXT("HealthComp"));
    HealthComp->OnHealthChanged.AddDynamic(this, &ASExplosiveBarrel::OnHealthChanged);

   
    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetSimulatePhysics(true);
    MeshComp->SetCollisionObjectType(ECC_PhysicsBody);
    RootComponent = MeshComp;

    RadialForceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
    RadialForceComp->SetupAttachment(MeshComp);
    RadialForceComp->Radius = 250;
    RadialForceComp->bImpulseVelChange = true;
    RadialForceComp->bAutoActivate = false;
    RadialForceComp->bIgnoreOwningActor = true;

    ExplosionImpulse = 400;
}

void ASExplosiveBarrel::OnHealthChanged(USHealthComponent* OwningHealthComp, float Health, float HealthDelta,
    const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (bExploded)
    {
        return;
    }

    if (Health <= 0.0f)
    {
        bExploded = true;

        FVector BoostIntensity = FVector::UpVector * ExplosionImpulse;
        MeshComp->AddImpulse(BoostIntensity, NAME_None, true);

        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
        MeshComp->SetMaterial(0, ExplodedMaterial);

        RadialForceComp->FireImpulse();        
    }
}

