// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PaintItOutHUD.generated.h"

UCLASS()
class APaintItOutHUD : public AHUD
{
	GENERATED_BODY()

public:
	APaintItOutHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

