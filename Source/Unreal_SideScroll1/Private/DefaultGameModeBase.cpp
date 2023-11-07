// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultGameModeBase.h"
#include "Unreal_SideScroll1Character.h"

ADefaultGameModeBase::ADefaultGameModeBase()
{
    //기본 스폰 캐릭터 설정
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Character(TEXT("Blueprint'/Game/Asset/SideScrollerCPP/Blueprints/SideScrollerCharacter.SideScrollerCharacter_C'"));
    if(BP_Character.Succeeded())
        DefaultPawnClass = BP_Character.Class;
}