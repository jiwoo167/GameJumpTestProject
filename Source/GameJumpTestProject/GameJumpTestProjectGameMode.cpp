// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJumpTestProjectGameMode.h"
#include "GameJumpTestProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameJumpTestProjectGameMode::AGameJumpTestProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
