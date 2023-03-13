// Paint It Out Game Demo


#include "Weapon/PaintWeaponComponent.h"
#include "GameFramework/Character.h"

UPaintWeaponComponent::UPaintWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPaintWeaponComponent::AttachWeaponToPlayer(USceneComponent* AttachTo)
{
	Weapon->AttachToComponent(AttachTo, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),
	                          GripPointSocketName);
}

void UPaintWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}

void UPaintWeaponComponent::SpawnWeapon()
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	UWorld* World = GetWorld();
	if (!World) return;

	const auto CreatedWeapon = World->SpawnActor<APaintWeapon>(WeaponToSpawn);
	if (!CreatedWeapon) return;

	CreatedWeapon->SetOwner(Character);
	Weapon = CreatedWeapon;

	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
	Weapon->AttachToComponent(Character->GetMesh(), AttachmentRules, GripPointSocketName);
}
