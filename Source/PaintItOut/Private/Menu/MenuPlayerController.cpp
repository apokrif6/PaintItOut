// Paint It Out Game Demo


#include "Menu/MenuPlayerController.h"

void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}
