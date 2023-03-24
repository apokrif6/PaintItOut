// Paint It Out Game Demo


#include "Menu/UI/SelectTeamColorItemWidget.h"

void USelectTeamColorItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!TeamColorSelectButton) return;

	TeamColorSelectButton->OnClicked.AddDynamic(this, &USelectTeamColorItemWidget::OnTeamColorClicked);
}

void USelectTeamColorItemWidget::SetTeamColorData(const FSelectTeamColorData& Data)
{
	TeamColorData = Data;

	if (TeamColorTextBlock)
	{
		TeamColorTextBlock->SetText(FText::FromName(TeamColorData.Name));
	}

	if (TeamColorImage)
	{
		TeamColorImage->SetColorAndOpacity(TeamColorData.Color.WithAlpha(255));
	}
}

void USelectTeamColorItemWidget::SetItemSelected(bool IsSelected)
{
	if (!FrameImage) return;

	FrameImage->SetVisibility(IsSelected ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void USelectTeamColorItemWidget::OnTeamColorClicked()
{
	OnTeamColorSelected.Broadcast(TeamColorData);
}
