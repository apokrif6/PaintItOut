// Paint It Out Game Demo


#include "Menu/UI/MenuUserWidget.h"
#include "PaintItOutGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UMenuUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &UMenuUserWidget::OnStartGame);
	}

	InitTeamColorItems();
}

void UMenuUserWidget::InitTeamColorItems()
{
	const auto PaintItOutGameInstance = GetPaintItOutGameInstance();
	if (!PaintItOutGameInstance) return;

	if (!TeamColorItemsBox) return;
	TeamColorItemsBox->ClearChildren();

	for (auto TeamColorData : PaintItOutGameInstance->GetTeamColorsData())
	{
		const auto TeamColorWidget = CreateWidget<USelectTeamColorItemWidget>(GetWorld(), TeamColorItemWidgetClass);
		if (!TeamColorWidget) continue;

		TeamColorWidget->SetTeamColorData(TeamColorData);
		TeamColorWidget->OnTeamColorSelected.AddUObject(this, &UMenuUserWidget::OnTeamColorSelected);

		TeamColorItemsBox->AddChild(TeamColorWidget);

		TeamColorItemWidgets.Add(TeamColorWidget);
	}

	OnTeamColorSelected(PaintItOutGameInstance->GetTeamColorsData()[0]);
}

void UMenuUserWidget::OnTeamColorSelected(const FSelectTeamColorData& Data)
{
	const auto PaintItOutGameInstance = GetPaintItOutGameInstance();
	if (!PaintItOutGameInstance) return;

	PaintItOutGameInstance->SetSelectedTeamColorData(Data);

	for (const auto TeamColorItemWidget : TeamColorItemWidgets)
	{
		if (TeamColorItemWidget)
		{
			const bool IsSelected = Data.Color == TeamColorItemWidget->GetTeamColorData().Color;
			TeamColorItemWidget->SetItemSelected(IsSelected);
		}
	}
}

void UMenuUserWidget::OnStartGame()
{
	const UWorld* World = GetWorld();
	if (!World) return;

	const auto PaintItOutGameInstance = GetPaintItOutGameInstance();
	if (!PaintItOutGameInstance) return;

	const FName StartupLevelName = PaintItOutGameInstance->GetStartupLevelName();

	if (StartupLevelName.IsNone()) return;

	UGameplayStatics::OpenLevel(this, StartupLevelName);
}

UPaintItOutGameInstance* UMenuUserWidget::GetPaintItOutGameInstance() const
{
	const auto World = GetWorld();
	if (!World) return nullptr;

	return World->GetGameInstance<UPaintItOutGameInstance>();
}
