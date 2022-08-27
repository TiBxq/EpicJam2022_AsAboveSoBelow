// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsAboveSoBelowGameMode.h"
#include "AsAboveSoBelowCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAsAboveSoBelowGameMode::AAsAboveSoBelowGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
