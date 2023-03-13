// Paint It Out Game Demo


#include "Weapon/PaintWeaponComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UPaintWeaponComponent::UPaintWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPaintWeaponComponent::AttachWeaponToPlayer(USceneComponent* AttachTo) const
{
	Weapon->AttachToComponent(AttachTo, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),
	                          GripPointSocketName);
}

void UPaintWeaponComponent::OnFire()
{
	Weapon->Fire();

	PlayFireSound();
	PlayFireAnimation();
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

void UPaintWeaponComponent::PlayFireSound()
{
	USoundBase* FireSound = FireData.FireSound;
	if (!FireSound) return;

	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetOwner()->GetActorLocation());
}

void UPaintWeaponComponent::PlayFireAnimation()
{
	UAnimMontage* FireAnimation = FireData.FireAnimation;
	if (!FireAnimation) return;

	ACharacter* WeaponOwner = Cast<ACharacter>(GetOwner());
	if (!WeaponOwner) return;

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, WeaponOwner->GetName());

	WeaponOwner->PlayAnimMontage(FireAnimation);
}
