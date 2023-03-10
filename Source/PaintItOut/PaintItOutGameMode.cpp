// Copyright Epic Games, Inc. All Rights Reserved.

#include "PaintItOutGameMode.h"
#include "PaintItOutHUD.h"
#include "PaintItOutCharacter.h"
#include "UObject/ConstructorHelpers.h"

APaintItOutGameMode::APaintItOutGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APaintItOutHUD::StaticClass();
}
