// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal_SideScroll1GameMode.h"
#include "Unreal_SideScroll1Character.h"
#include "UObject/ConstructorHelpers.h"

AUnreal_SideScroll1GameMode::AUnreal_SideScroll1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Asset/SideScrollerCPP/Blueprints/SideScrollerCharacter.SideScrollerCharacter_C'"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
