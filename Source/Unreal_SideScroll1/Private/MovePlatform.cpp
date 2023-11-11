// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform.h"
#include "Components/InterpToMovementComponent.h"

// Sets default values
AMovePlatform::AMovePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	InterpToMove = CreateDefaultSubobject<UInterpToMovementComponent>(TEXT("InterpToMove"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Asset/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if(SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMovePlatform::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	InterpToMove->BehaviourType = EInterpToBehaviourType::PingPong;
	InterpToMove->AddControlPointPosition(Start,true);
	InterpToMove->AddControlPointPosition(End,true);
	InterpToMove->Duration = DurationTime;
}

// Called every frame
void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

