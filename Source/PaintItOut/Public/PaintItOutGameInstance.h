// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Menu/SelectTeamColorData.h"
#include "PaintItOutGameInstance.generated.h"

UCLASS()
class PAINTITOUT_API UPaintItOutGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FName GetStartupLevelName() const { return StartupLevelName; }

	void SetSelectedTeamColorData(const FSelectTeamColorData& TeamColorData) { SelectedTeamColorData = TeamColorData; }

	FSelectTeamColorData GetSelectedTeamColorData() const { return SelectedTeamColorData; }

	TArray<FSelectTeamColorData> GetTeamColorsData() const { return TeamColorsData; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = Game)
	TArray<FSelectTeamColorData> TeamColorsData;

	UPROPERTY(EditDefaultsOnly, Category = Game)
	FName StartupLevelName = NAME_None;

private:
	FSelectTeamColorData SelectedTeamColorData;
};
