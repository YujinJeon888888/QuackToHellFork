// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuackToHellGameMode.h"
#include "QuackToHellCharacter.h"
#include "UObject/ConstructorHelpers.h"

AQuackToHellGameMode::AQuackToHellGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
