// Paint It Out Game Demo

#pragma once

#include "CoreMinimal.h"
#include "PaintWeapon.h"
#include "Components/ActorComponent.h"
#include "PaintWeaponComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PAINTITOUT_API UPaintWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPaintWeaponComponent();

	void AttachWeaponToPlayer(USceneComponent* AttachTo);

protected:
	UPROPERTY(EditDefaultsOnly, Category = Weapon)
	TSubclassOf<APaintWeapon> WeaponToSpawn;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	APaintWeapon* Weapon = nullptr;

	UPROPERTY()
	FName GripPointSocketName = "GripPoint";
	
	void SpawnWeapon();
};
