// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

UCLASS()
class PAINTITOUT_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UUserWidget> MenuWidgetClass;
	
	virtual void BeginPlay() override;
};
