// Fill out your copyright notice in the Description page of Project Settings.


#include "InputButton.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/PanelSlot.h"
#include "Components/ButtonSlot.h"

#if WITH_EDITOR

// void UInputButton::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
// {
//     Super::PostEditChangeProperty(PropertyChangedEvent);

//     Button_Image->SetBrush(Button_Brush);
// }

#endif
void UInputButton::NativePreConstruct()
{
    Super::NativePreConstruct();

    Button_Image->SetBrush(Button_Brush);
    Cast<UButtonSlot>(Button_Image->Slot)->SetPadding(Button_Margin);
}
