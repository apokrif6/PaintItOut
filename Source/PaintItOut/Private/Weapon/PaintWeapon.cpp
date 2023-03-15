// Paint It Out Game Demo


#include "Weapon/PaintWeapon.h"

#include "Kismet/GameplayStatics.h"
#include "PaintItOut/PaintItOutCharacter.h"

APaintWeapon::APaintWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	Mesh->CastShadow = false;
	Mesh->bCastDynamicShadow = false;

	SetRootComponent(Mesh);

	SetProjectileTeamColor();
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

void APaintWeapon::SetProjectileTeamColor() const
{
	const APaintItOutCharacter* Character = Cast<APaintItOutCharacter>(
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!Character) return;

	APaintBaseProjectile::SetProjectileColor(Character->GetTeamColor());
}
