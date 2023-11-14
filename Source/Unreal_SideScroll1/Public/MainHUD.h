// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_SIDESCROLL1_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta=(BindWidget))
	class UInputButton* Button_Jump;

	UPROPERTY(meta=(BindWidget))
	class UInputButton* Button_LeftMove;

	UPROPERTY(meta=(BindWidget))
	class UInputButton* Button_RightMove;
};
