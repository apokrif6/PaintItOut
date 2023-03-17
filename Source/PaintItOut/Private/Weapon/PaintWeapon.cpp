// Paint It Out Game Demo


#include "Weapon/PaintWeapon.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "PaintItOut/PaintItOutCharacter.h"

APaintWeapon::APaintWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	Mesh->CastShadow = false;
	Mesh->bCastDynamicShadow = false;

	SetRootComponent(Mesh);
}

void APaintWeapon::BeginPlay()
{
	Super::BeginPlay();
}

FVector APaintWeapon::GetMuzzleWorldLocation() const
{
	return Mesh->GetSocketLocation(MuzzleSocketName);
}

void APaintWeapon::Fire() const
{
	if (!Projectile) return;

	UWorld* World = GetWorld();
	if (!World) return;

	const auto Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	const FRotator SpawnRotation = Controller->GetControlRotation();
	const FVector SpawnLocation = GetMuzzleWorldLocation();

	FActorSpawnParameters ProjectileSpawnParams;
	ProjectileSpawnParams.SpawnCollisionHandlingOverride =
		ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	World->SpawnActor<APaintBaseProjectile>(Projectile, SpawnLocation, SpawnRotation, ProjectileSpawnParams);
}

void APaintWeapon::SetWeaponTeamColor(FColor Color) const
{
	UMaterialInterface* WeaponMaterial = Mesh->GetMaterial(0);

	UMaterialInstanceDynamic* DynamicWeaponMeshMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(
		nullptr, WeaponMaterial);
	DynamicWeaponMeshMaterial->SetVectorParameterValue(WeaponMaterialColorParamName, Color);

	Mesh->SetMaterial(0, DynamicWeaponMeshMaterial);
}
