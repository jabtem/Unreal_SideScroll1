// Fill out your copyright notice in the Description page of Project Settings.


#include "DissolvePlatform.h"

// Sets default values
ADissolvePlatform::ADissolvePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/Asset/Geometry/Meshes/1M_Cube.1M_Cube'"));
	if(SM.Succeeded())
		Mesh->SetStaticMesh(SM.Object);

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> DissolveMaterial(TEXT("MaterialInstanceConstant'/Game/Resource/Materials/SimpleDissolve_Inst.SimpleDissolve_Inst'"));
	if(DissolveMaterial.Succeeded())
		Mesh->SetMaterial(0,DissolveMaterial.Object);

	//활성화 유지시간
	ActiveTime = 2.f;
	//비활성화 유지시간
	DeActiveTime = 2.f;
	bIsDissolve = false;
	bIsTimeStop = false;
	//DissolveAmount의 기본값
	DissolveAmount =0.01f;
	//디졸브 속도
	DissolveSpeed = 1.f;
	bIsActive = true;
}

// Called when the game starts or when spawned
void ADissolvePlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADissolvePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(!bIsTimeStop)
		Time += DeltaTime;

	if(Time >= ActiveTime && !bIsDissolve)
	{
		//타이머를 정지
		bIsTimeStop = true;
		bIsDissolve = true;
		Time =0.f;
	}
	else if(Time >= DeActiveTime && bIsDissolve)
	{
		//타이머를 정지
		bIsTimeStop = true;
		bIsDissolve = false;
		Time =0.f;
	}

	DissolveObject(DeltaTime);
}

void ADissolvePlatform::DissolveObject(float DeltaTime)
{
	if(!bIsTimeStop)
		return;

	if(bIsDissolve)
	{
		DissolveAmount = FMath::FInterpTo(DissolveAmount,1.f,DeltaTime, DissolveSpeed);
		if(DissolveAmount >=0.95f)
		{	
			DissolveAmount = 1.f;
			bIsTimeStop = false;
			if(bIsActive)
			{
				SetActorHiddenInGame(true);
				bIsActive = false;
			}
			//콜리전 비활성화
			SetActorEnableCollision(false);
		}
		Mesh->SetScalarParameterValueOnMaterials("DissolveAmount",DissolveAmount);

	}
	else
	{
		DissolveAmount = FMath::FInterpTo(DissolveAmount,0.01f,DeltaTime, DissolveSpeed);
		if(!bIsActive)
		{
			SetActorHiddenInGame(false);
			bIsActive = true;			
		}
		//일정이상 오브젝트가 나타나면 콜리전 활성화
		if(!GetActorEnableCollision() && DissolveAmount <= 0.5f)
			SetActorEnableCollision(true);

		if(DissolveAmount <=0.05f)
		{
			DissolveAmount = 0.01f;
			bIsTimeStop = false;
		}
		Mesh->SetScalarParameterValueOnMaterials("DissolveAmount",DissolveAmount);
	}
}

