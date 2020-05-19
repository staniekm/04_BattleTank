

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/WidgetComponent.h"
#include "PaintingGrid.h"

#include "PaintingPicker.generated.h"

UCLASS()
class VR_LIGHTPAINTER_API APaintingPicker : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintingPicker();

	void AddPainting();

	void ToggleDeleteMode();

	void UpdateCurrentPage(int32 Offset);

protected:
	virtual void BeginPlay() override;

private:
	UPaintingGrid* GetPaintingGrid() const { return Cast<UPaintingGrid>(PaintingGrid->GetUserWidgetObject()); }

	void Refresh() { RefreshSlots(); RefreshDots(); }
	void RefreshSlots();
	int32 GetNumberOfPages() const;
	void RefreshDots();


	// References
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaintingGrid;

	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* ActionBar;

	// State
	UPROPERTY(EditAnywhere)
	int32 CurrentPage = 0;
};
