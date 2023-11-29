// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveLevel.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlayCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

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
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),PortalEffect, FVector(0.f,1000.f,930.f),GetActorRotation());
	}
}

void AMoveLevel::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if(Character)
	{
		UGameplayStatics::OpenLevel(this, FName(LevelName));
	}
}

