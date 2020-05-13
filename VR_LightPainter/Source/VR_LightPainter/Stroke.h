// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/InstancedStaticMeshComponent.h"

#include "Stroke.generated.h"

UCLASS()
class VR_LIGHTPAINTER_API AStroke : public AActor
{
	GENERATED_BODY()
	
public:	
	AStroke();
	
	void Update(FVector CursorLocation);

private:

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	// Config

	UPROPERTY(VisibleAnywhere)
	UInstancedStaticMeshComponent* StrokeMeshes;

	//UPROPERTY(VisibleAnywhere)


	// State
	FVector PreviousCursorLocation;
};
