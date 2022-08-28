// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FirstPersonCharacter.h"
#include "MyCharacter.generated.h"

class UHealthComponent;

// Declaration of the delegate that will be called when the Primary Action is triggered
// It is declared as dynamic so it can be accessed also in Blueprints
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterOnUseItem);

UCLASS()
class ASABOVESOBELOW_API AMyCharacter : public AFirstPersonCharacter
{
	GENERATED_BODY()

	AMyCharacter(const FObjectInitializer& ObjectInitializer);

public:
	UHealthComponent* GetHealthComponent() const { return HealthComponent; }

	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FCharacterOnUseItem OnUseItem;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Health, meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	/** Fires a projectile. */
	void OnPrimaryAction();

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
};
