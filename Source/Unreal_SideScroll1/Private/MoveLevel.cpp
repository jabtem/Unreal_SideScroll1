// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLevel.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlayCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Engine/AssetManager.h"
#include "LevelSequenceActor.h"

// Sets default values
AMoveLevel::AMoveLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	RootComponent = Trigger;
	Trigger->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
}

// Called when the game starts or when spawned
void AMoveLevel::BeginPlay()
{
	Super::BeginPlay();
	
	if(PortalEffect)
	{
		NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),PortalEffect, FVector(0.f,1000.f,930.f),GetActorRotation());
	}

}

void AMoveLevel::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if(Character)
	{
		LevelSequenceActor->SequencePlayer->OnFinished.AddDynamic(this,&AMoveLevel::OnLevelSequencePlayEnded);
		LevelSequenceActor->SequencePlayer->PlayReverse();
		//Character->SetActorLocation(FVector(0.f,106.69f,200.f));
		//레벨 이동
		// UGameplayStatics::OpenLevel(this, FName(LevelName));
	}
}
void AMoveLevel::OnLevelSequencePlayEnded()
{
	//레벨 스트리밍
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;
    LatentInfo.ExecutionFunction = "OnLevelLoaded";
    LatentInfo.Linkage = 0;
    LatentInfo.UUID = 0;
	UGameplayStatics::LoadStreamLevel(this, FName(NextLevelName),true, false, LatentInfo);
}

void AMoveLevel::OnLevelLoaded()
{
	GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(FVector(0.f,106.69f,200.f));
	NiagaraComp->Deactivate();
	NiagaraComp->DestroyComponent();
	FLatentActionInfo LatentInfo;
	UGameplayStatics::UnloadStreamLevel(this, FName(PrevLevelName), LatentInfo,true);
}


