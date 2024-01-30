// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveLevel.generated.h"

UCLASS()
class UNREAL_SIDESCROLL1_API AMoveLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

private:
	UFUNCTION()
	void OnLevelLoaded();

	UFUNCTION()
	void OnLevelSequencePlayEnded();

private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MoveLevel, Meta=(AllowPrivateAccess=true))
	FString PrevLevelName;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MoveLevel, Meta=(AllowPrivateAccess=true))
	FString NextLevelName;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MoveLevel, Meta=(AllowPrivateAccess=true))
	class UNiagaraSystem* PortalEffect;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MoveLevel, Meta=(AllowPrivateAccess=true))
	class ALevelSequenceActor* LevelSequenceActor;

	UPROPERTY()
	class UNiagaraComponent* NiagaraComp;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* Trigger;

};
