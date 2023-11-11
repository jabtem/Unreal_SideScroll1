// Fill out your copyright notice in the Description page of Project Settings.


#include "BouncePlatform.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayCharacter.h"
// Sets default values
ABouncePlatform::ABouncePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Asset/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if(SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
	RootComponent = Mesh;

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(RootComponent);

	BounceDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("BouceDirection"));
	BounceDirection->SetupAttachment(RootComponent);
	BounceDirection->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	BounceDirection->ArrowLength = 200.f;
}

// Called when the game starts or when spawned
void ABouncePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABouncePlatform::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Trigger->OnComponentBeginOverlap.AddDynamic(this,&ABouncePlatform::OnCharacterOverlap);
}

//캐릭터와 접촉하면 화살표 방향으로 날려보냄 
void ABouncePlatform::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp,
 										 AActor* OtherActor, 
  										 UPrimitiveComponent* OtherComp,
  										 int32 OtherBodyIndex,
 										 bool bFromSweep,
 										 const FHitResult& SweepResult)
{
	APlayCharacter* PlayCharacter = Cast<APlayCharacter>(OtherActor);
	if(PlayCharacter)
	{
		PlayCharacter->GetCharacterMovement()->AddImpulse(BounceDirection->GetForwardVector()*BouncePower,true);
	}
}



