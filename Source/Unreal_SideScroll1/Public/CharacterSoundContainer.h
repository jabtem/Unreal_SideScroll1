// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterSoundContainer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class UNREAL_SIDESCROLL1_API UCharacterSoundContainer : public UObject
{
	GENERATED_BODY()
	
	public:
		class USoundCue* GetJumpSound(){return JumpSound;}
	private:
		UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Sound, Meta=(AllowPrivateAccess=true))
		class USoundCue* JumpSound;
};
