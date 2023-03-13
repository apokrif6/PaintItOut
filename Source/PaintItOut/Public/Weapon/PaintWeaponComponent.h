// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "PaintWeapon.h"
#include "Components/ActorComponent.h"
#include "PaintWeaponComponent.generated.h"

USTRUCT(BlueprintType)
struct FFireData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile)
	USoundBase* FireSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile)
	UAnimMontage* FireAnimation;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PAINTITOUT_API UPaintWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPaintWeaponComponent();

	void AttachWeaponToPlayer(USceneComponent* AttachTo) const;

	void OnFire();

protected:
	UPROPERTY(EditDefaultsOnly, Category = Weapon)
	TSubclassOf<APaintWeapon> WeaponToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
	FFireData FireData;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	APaintWeapon* Weapon = nullptr;

	UPROPERTY()
	FName GripPointSocketName = "GripPoint";

	void SpawnWeapon();

	void PlayFireSound();

	void PlayFireAnimation();
};
