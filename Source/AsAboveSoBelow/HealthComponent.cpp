// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::TakeDamage(float Damage)
{
	if (IsAlive())
	{
		Health = FMath::Max(Health - Damage, 0.f);

		OnDamageTaken.Broadcast(Damage);

		if (Health <= 0.f)
		{
			OnDeath.Broadcast();
		}
	}
}

void UHealthComponent::Heal(float Amount)
{
	if (IsAlive())
	{
		Health = FMath::Min(Health + Amount, MaxHealth);
	}
}

