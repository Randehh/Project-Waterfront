// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Project_WaterfrontGameMode.h"
#include "Project_WaterfrontCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_WaterfrontGameMode::AProject_WaterfrontGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
