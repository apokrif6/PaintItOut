// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaintBaseProjectile.generated.h"

UCLASS()
class PAINTITOUT_API APaintBaseProjectile : public AActor
{
	GENERATED_BODY()

public:
	APaintBaseProjectile();

	static void SetProjectileColor(FColor Color);

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile)
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	UMaterialInterface* PaintBlobDecalMaterial;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	FFloatInterval PaintBlobSideSizeInterval = FFloatInterval{75.0f, 100.0f};

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile, Meta = (ClampMin = 1.0f))
	float ProjectileLifeSpan = 3.0f;

	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	           const FHitResult& Hit);

	void SpawnPaintBlobDecal(UPrimitiveComponent* ComponentToAttach, const FHitResult& Hit) const;

	float GetPaintBlobRandomSideSize() const;

	float GetPaintBlobRandomRelativeLocation() const;

	static FColor Color;

	const FName BlobMaterialColorParamName = "Color";
};
