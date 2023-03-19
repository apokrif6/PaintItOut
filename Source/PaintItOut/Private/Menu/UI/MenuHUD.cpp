// Paint It Out Game Demo


#include "Menu/UI/MenuHUD.h"
#include "Blueprint/UserWidget.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	const auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
	if (!MenuWidget) return;

	MenuWidget->AddToViewport();
}
