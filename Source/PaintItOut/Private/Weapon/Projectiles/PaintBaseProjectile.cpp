// Paint It Out Game Demo


#include "Weapon/Projectiles/PaintBaseProjectile.h"

APaintBaseProjectile::APaintBaseProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	Collision->InitSphereRadius(5.0f);
	Collision->BodyInstance.SetCollisionProfileName("Projectile");
	Collision->OnComponentHit.AddDynamic(this, &APaintBaseProjectile::OnHit);
	Collision->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	Collision->CanCharacterStepUpOn = ECB_No;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = Collision;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	InitialLifeSpan = ProjectileLifeSpan;

	SetRootComponent(Collision);
}

void APaintBaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void APaintBaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                 FVector NormalImpulse, const FHitResult& Hit)
{
	if (!OtherActor
		|| OtherActor == this
		|| !OtherComp
		|| !OtherComp->IsSimulatingPhysics()
	)
		return;

	OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

	Destroy();
}
