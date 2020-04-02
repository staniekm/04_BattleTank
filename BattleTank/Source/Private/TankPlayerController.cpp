// Fill out your copyright notice in the Description page of Project Settings.

//#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    if (!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s"), *(ControlledTank->GetName()));
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // AimTowardCrosshair();
    UE_LOG(LogTemp, Warning, TEXT("Player controller ticking"));
}

ATank *ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
    if(!GetControlledTank())
    {
        return;
    }
    // get world location if linetrace through crosshair
    //if it hits the landscape
        //tell controlled tank to aim at this point
}