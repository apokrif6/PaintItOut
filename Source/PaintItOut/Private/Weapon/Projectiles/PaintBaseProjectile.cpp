// Paint It Out Game Demo


#include "Weapon/Projectiles/PaintBaseProjectile.h"

APaintBaseProjectile::APaintBaseProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMesh>(TEXT("ProjectileMesh"));
}

void APaintBaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}