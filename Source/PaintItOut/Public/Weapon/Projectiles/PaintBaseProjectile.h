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

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile)
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile)
	FColor Color = FColor::Yellow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile, Meta = (ClampMin = 1.0f))
	float ProjectileLifeSpan = 3.0f;

	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	           const FHitResult& Hit);
};
