// Paint It Out Game Demo


#include "Weapon/PaintWeapon.h"

APaintWeapon::APaintWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	//TODO
	//Multiplayer features
	SetRootComponent(Mesh);
}

void APaintWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void APaintWeapon::Fire() const
{
}