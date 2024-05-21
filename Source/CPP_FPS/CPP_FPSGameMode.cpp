// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_FPSGameMode.h"
#include "CPP_FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPP_FPSGameMode::ACPP_FPSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
