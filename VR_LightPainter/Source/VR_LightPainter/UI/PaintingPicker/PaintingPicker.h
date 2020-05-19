

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/WidgetComponent.h"

#include "PaintingPicker.generated.h"

UCLASS()
class VR_LIGHTPAINTER_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintingPicker();

	void AddPainting();

	void ToggleDeleteMode();

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* PaintingGrid;

	UPROPERTY(VisibleAnywhere)
		UWidgetComponent* ActionBar;

	void RefreshSlots();
};
