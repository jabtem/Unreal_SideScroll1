// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_SIDESCROLL1_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Pawn, Meta=(AllowPrivateAccess=true))
	float Speed;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Pawn, Meta=(AllowPrivateAccess=true))
	bool IsFalling;

};
