// Paint It Out Game Demo


#include "Weapon/PaintWeapon.h"

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

void APaintWeapon::Fire() const
{
}