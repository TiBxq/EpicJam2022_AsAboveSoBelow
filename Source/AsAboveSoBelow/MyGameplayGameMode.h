// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameplayGameMode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterAstralWorld);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExitAstralWorld);

UCLASS()
class ASABOVESOBELOW_API AMyGameplayGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	void EnterAstralWorld();

	UFUNCTION(BlueprintCallable)
	void ExitAstralWorld();

	UFUNCTION(BlueprintCallable)
	bool IsInAstralWorld() const { return bIsInAstralWorld; }

	UPROPERTY(BlueprintAssignable, Category = "World")
	FOnEnterAstralWorld OnEnterAstralWorld;

	UPROPERTY(BlueprintAssignable, Category = "World")
	FOnEnterAstralWorld OnExitAstralWorld;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsInAstralWorld;
};
