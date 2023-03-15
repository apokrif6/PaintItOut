// Paint It Out Game Demo


#include "Weapon/Projectiles/PaintBaseProjectile.h"

#include "Components/DecalComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "PaintItOut/PaintItOutCharacter.h"

FColor APaintBaseProjectile::Color;

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
	)
		return;

	if (OtherComp->IsSimulatingPhysics())
		OtherComp->AddImpulseAtLocation(GetVelocity() * 25.0f, GetActorLocation());

	SpawnPaintBlobDecal(OtherComp, Hit);

	Destroy();
}

void APaintBaseProjectile::SpawnPaintBlobDecal(UPrimitiveComponent* ComponentToAttach, const FHitResult& Hit) const
{
	UMaterialInstanceDynamic* DynamicPaintBlobMaterial = UKismetMaterialLibrary::CreateDynamicMaterialInstance(
		nullptr, PaintBlobDecalMaterial);
	DynamicPaintBlobMaterial->SetVectorParameterValue("Color", Color);

	const FVector DecalSize = FVector{-30.f, GetPaintBlobRandomSideSize(), GetPaintBlobRandomSideSize()};
	const FRotator HitRotator = UKismetMathLibrary::MakeRotFromX(Hit.Normal);

	UDecalComponent* PaintBlobDecal = UGameplayStatics::SpawnDecalAttached(
		DynamicPaintBlobMaterial, DecalSize, ComponentToAttach, NAME_None, GetActorLocation(), HitRotator,
		EAttachLocation::KeepWorldPosition);
	PaintBlobDecal->AddRelativeRotation(FRotator{0.0f, 0.0f, GetPaintBlobRandomRelativeLocation()});
}

float APaintBaseProjectile::GetPaintBlobRandomSideSize() const
{
	return UKismetMathLibrary::RandomFloatInRange(PaintBlobSideSizeInterval.Min, PaintBlobSideSizeInterval.Max);
}

float APaintBaseProjectile::GetPaintBlobRandomRelativeLocation() const
{
	return UKismetMathLibrary::RandomFloatInRange(0.0f, 360.0f);
}

void APaintBaseProjectile::SetProjectileColor(FColor ProjectileColor)
{
	Color = ProjectileColor;
}
