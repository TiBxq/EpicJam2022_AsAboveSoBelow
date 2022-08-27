// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

AMyCharacter::AMyCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	GetCamera()->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	GetMesh()->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	GetMesh()->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind fire event
	PlayerInputComponent->BindAction("PrimaryAction", IE_Pressed, this, &AMyCharacter::OnPrimaryAction);
}

void AMyCharacter::OnPrimaryAction()
{
	// Trigger the OnItemUsed Event
	OnUseItem.Broadcast();
}