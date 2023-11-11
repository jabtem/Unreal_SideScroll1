// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultGameModeBase.h"
#include "Unreal_SideScroll1Character.h"
#include "MainHUD.h"

ADefaultGameModeBase::ADefaultGameModeBase()
{
    //기본 스폰 캐릭터 설정
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Character(TEXT("Blueprint'/Game/BluePrints/Actor/Player/BP_PlayCharacter.BP_PlayCharacter_C'"));
    if(BP_Character.Succeeded())
        DefaultPawnClass = BP_Character.Class;

    static ConstructorHelpers::FClassFinder<UMainHUD> WBP_MainHUD(TEXT("WidgetBlueprint'/Game/BluePrints/UI/WBP_MainHUD.WBP_MainHUD_C'"));
    if(WBP_MainHUD.Succeeded())
    {
        HUD_Class = WBP_MainHUD.Class;

        CurrentWidget = CreateWidget(GetWorld(),HUD_Class);
        if(CurrentWidget)
            CurrentWidget->AddToViewport();
    }

}