


#include "PaintingPicker.h"

#include "VR_LightPainter/Saving/PainterSaveGameIndex.h"
#include "VR_LightPainter/Saving/PainterSaveGame.h"

#include "ActionBar.h"

//#include "PaintingGrid.h"

APaintingPicker::APaintingPicker()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	PaintingGrid = CreateDefaultSubobject<UWidgetComponent>(TEXT("PaintingGrid"));
	PaintingGrid->SetupAttachment(GetRootComponent());

	ActionBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("ActionBar"));
	ActionBar->SetupAttachment(GetRootComponent());
}


void APaintingPicker::BeginPlay()
{
	Super::BeginPlay();
	
	UActionBar* ActionBarWidget = Cast<UActionBar>(ActionBar->GetUserWidgetObject());
	if (ActionBarWidget)
	{
		ActionBarWidget->SetParentPicker(this);
	}

	Refresh();
}

int32 APaintingPicker::GetNumberOfPages() const
{
	if (!GetPaintingGrid()) return 0;

	int32 TotalNumberOfSlots = UPainterSaveGameIndex::Load()->GetSlotNames().Num();
	int32 SlotPerPage = GetPaintingGrid()->GetNumberOfSlots();
	
	return FMath::CeilToInt((float)TotalNumberOfSlots / SlotPerPage);
}

void APaintingPicker::RefreshDots()
{
	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->ClearPaginationDots();

	for (int32 i = 0; i <GetNumberOfPages(); ++i)
	{
		GetPaintingGrid()->AddPaginationDot(CurrentPage == i);

	}

}

void APaintingPicker:: RefreshSlots()
{
	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->ClearPaintings();

	int32 Index = 0;
	for (FString SlotName : UPainterSaveGameIndex::Load()->GetSlotNames())
	{
		GetPaintingGrid()->AddPainting(Index, SlotName);
		++Index;
	}
}

void APaintingPicker::AddPainting()
{
	UPainterSaveGame::Create();

	Refresh();
}

void APaintingPicker::ToggleDeleteMode()
{
	if (!GetPaintingGrid()) return;

	GetPaintingGrid()->ClearPaintings();
}

void APaintingPicker::UpdateCurrentPage(int32 Offset)
{
	CurrentPage += FMath::Clamp(CurrentPage + Offset, 0, GetNumberOfPages()-1);

	Refresh();
}

