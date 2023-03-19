// Paint It Out Game Demo


#include "Menu/MenuGameModeBase.h"
#include "Menu/MenuPlayerController.h"
#include "Menu/UI/MenuHUD.h"

AMenuGameModeBase::AMenuGameModeBase()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}