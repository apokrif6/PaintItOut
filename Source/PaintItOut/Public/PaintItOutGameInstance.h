// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PaintItOutGameInstance.generated.h"

UCLASS()
class PAINTITOUT_API UPaintItOutGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FName GetStartupLevelName() const { return StartupLevelName; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = Game)
	FName StartupLevelName = NAME_None;
};
