// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Menu/SelectTeamColorData.h"
#include "SelectTeamColorItemWidget.generated.h"

UCLASS()
class PAINTITOUT_API USelectTeamColorItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	FOnTeamColorSelectedSignature OnTeamColorSelected;

	void SetTeamColorData(const FSelectTeamColorData& Data);

	FSelectTeamColorData GetTeamColorData() const { return TeamColorData; };

	void SetItemSelected(bool IsSelected);

protected:
	UPROPERTY(Meta = (BindWidget))
	UButton* TeamColorSelectButton;

	UPROPERTY(Meta = (BindWidget))
	UTextBlock* TeamColorTextBlock;

	UPROPERTY(Meta = (BindWidget))
	UImage* TeamColorImage = nullptr;

	UPROPERTY(Meta = (BindWidget))
	UImage* FrameImage;

	virtual void NativeOnInitialized() override;

private:
	FSelectTeamColorData TeamColorData;

	UFUNCTION()
	void OnTeamColorClicked();
};
