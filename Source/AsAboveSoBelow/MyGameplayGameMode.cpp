// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameplayGameMode.h"

void AMyGameplayGameMode::EnterAstralWorld()
{
	if (!bIsInAstralWorld)
	{
		bIsInAstralWorld = true;
		OnEnterAstralWorld.Broadcast();
	}
}

void AMyGameplayGameMode::ExitAstralWorld()
{
	if (bIsInAstralWorld)
	{
		bIsInAstralWorld = false;
		OnExitAstralWorld.Broadcast();
	}
}