// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "PaintItOutGameInstance.h"
#include "SelectTeamColorItemWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "MenuUserWidget.generated.h"

UCLASS()
class PAINTITOUT_API UMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	UButton* StartGameButton;

	UPROPERTY(Meta = (BindWidget))
	UHorizontalBox* TeamColorItemsBox;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UUserWidget> TeamColorItemWidgetClass;

	virtual void NativeOnInitialized() override;

private:
	UPROPERTY()
	TArray<USelectTeamColorItemWidget*> TeamColorItemWidgets;

	void InitTeamColorItems();

	void OnTeamColorSelected(const FSelectTeamColorData& Data);

	UPaintItOutGameInstance* GetPaintItOutGameInstance() const;

	UFUNCTION()
	void OnStartGame();
};
