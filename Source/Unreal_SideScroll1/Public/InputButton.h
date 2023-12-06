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
// #if WITH_EDITOR
// 	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
// #endif

protected:
	virtual void NativePreConstruct() override;
	
private :
	UPROPERTY(meta=(BindWidget))
	class UButton* Button_Action;

	UPROPERTY(meta=(BindWidget))
	class UImage* Button_Image;

	UPROPERTY(EditAnywhere)
	FSlateBrush Button_Brush;

	UPROPERTY(EditAnywhere)
	FMargin Button_Margin;

};
