

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/TextBlock.h"

#include "PaintingGridCard.generated.h"

/**
 * 
 */
UCLASS()
class VR_LIGHTPAINTER_API UPaintingGridCard : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetPaintingName(FString PaintingName);
	
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UTextBlock* SlotName;
};
