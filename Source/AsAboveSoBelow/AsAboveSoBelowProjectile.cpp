// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsAboveSoBelowProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "HealthComponent.h"
#include "MyCharacter.h"
#include "MyEnemy.h"
#include "MyGameplayGameMode.h"

AAsAboveSoBelowProjectile::AAsAboveSoBelowProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AAsAboveSoBelowProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AAsAboveSoBelowProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		bool IsAstral = false;
		if (AMyGameplayGameMode* MyGameMode = Cast<AMyGameplayGameMode>(GetWorld()->GetAuthGameMode()))
		{
			IsAstral = MyGameMode->IsInAstralWorld();
		}

		if (AMyCharacter* OtherCharacter = Cast<AMyCharacter>(OtherActor))
		{
			if (!IsAstral)
			{
				OtherCharacter->GetHealthComponent()->TakeDamage(Damage);
			}
		}
		else if (AMyEnemy* OtherEnemy = Cast<AMyEnemy>(OtherActor))
		{
			if (!IsAstral)
			{
				OtherEnemy->GetHealthComponent()->TakeDamage(Damage);
			}
		}
		else
		{
			if (OtherComp->IsSimulatingPhysics())
			{
				OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
			}
		}

		Destroy();
	}
}