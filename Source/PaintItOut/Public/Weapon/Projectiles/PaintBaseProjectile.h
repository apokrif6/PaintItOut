// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaintBaseProjectile.generated.h"

UCLASS()
class PAINTITOUT_API APaintBaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintBaseProjectile();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile)
	UStaticMesh* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile)
	FColor Color = FColor::Yellow;

	virtual void BeginPlay() override;
};
