// Paint It Out Game Demo


#include "Weapon/PaintWeaponComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "PaintItOut/PaintItOutCharacter.h"

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

	SetTeamColorForMaterials();
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

void UPaintWeaponComponent::PlayFireSound() const
{
	USoundBase* FireSound = FireData.FireSound;
	if (!FireSound) return;

	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetOwner()->GetActorLocation());
}

void UPaintWeaponComponent::PlayFireAnimation() const
{
	UAnimMontage* FireAnimation = FireData.FireAnimation;
	if (!FireAnimation) return;

	const APaintItOutCharacter* WeaponOwner = Cast<APaintItOutCharacter>(GetOwner());
	if (!WeaponOwner) return;

	UAnimInstance* AnimInstance = WeaponOwner->GetMesh1P()->GetAnimInstance();
	if (!AnimInstance) return;

	AnimInstance->Montage_Play(FireAnimation);
}

void UPaintWeaponComponent::SetTeamColorForMaterials() const
{
	const APaintItOutCharacter* WeaponOwner = Cast<APaintItOutCharacter>(GetOwner());
	if (!WeaponOwner) return;

	if (!GEngine) return;

	Weapon->SetWeaponTeamColor(WeaponOwner->GetTeamColor());

	APaintBaseProjectile::SetProjectileColor(WeaponOwner->GetTeamColor());
}
