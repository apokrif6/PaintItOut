// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MenuUserWidget.generated.h"

UCLASS()
class PAINTITOUT_API UMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Meta = (BindWidget))
	UButton* StartGameButton;
	
	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
	void OnStartGame();
};
