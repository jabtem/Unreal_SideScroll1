// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InputButton.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_SIDESCROLL1_API UInputButton : public UUserWidget
{
	GENERATED_BODY()

public:
	class UButton* GetActionButton(){return Button_Action;}
	
private :
	UPROPERTY(meta=(BindWidget))
	class UButton* Button_Action;

	UPROPERTY(EditAnywhere)
	class UTexture* Button_Icon;
};
