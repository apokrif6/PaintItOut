// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectiles/PaintBaseProjectile.h"
#include "PaintWeapon.generated.h"

UCLASS()
class PAINTITOUT_API APaintWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintWeapon();

	void Fire() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
	TSubclassOf<APaintBaseProjectile> Projectile;
	
	virtual void BeginPlay() override;

private:
	FName MuzzleSocketName = "Muzzle";

	FVector GetMuzzleWorldLocation() const;
};
