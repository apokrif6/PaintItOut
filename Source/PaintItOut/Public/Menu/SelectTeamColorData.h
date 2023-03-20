#pragma once

#include "SelectTeamColorData.generated.h"

USTRUCT(BlueprintType)
struct FSelectTeamColorData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Color)
	FColor TeamColor;
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnTeamColorSelectedSignature, const FSelectTeamColorData&)
