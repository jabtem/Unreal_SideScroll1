// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DefaultGameModeBase.generated.h"

UCLASS(MinimalAPI)
class ADefaultGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ADefaultGameModeBase();

public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Meta=(AllowPrivateAccess=true))
	TSubclassOf<UUserWidget> HUD_Class;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Meta=(AllowPrivateAccess=true))
	UUserWidget* CurrentWidget;

};
