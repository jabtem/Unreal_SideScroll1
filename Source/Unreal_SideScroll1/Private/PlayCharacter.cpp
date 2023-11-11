// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayCharacter::APlayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//스켈레탈메쉬 세팅
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeltalMesh(TEXT("SkeletalMesh'/Game/Asset/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if(SkeltalMesh.Succeeded())
		GetMesh()->SetSkeletalMesh(SkeltalMesh.Object);
	GetMesh()->SetWorldLocationAndRotation(FVector(0.f,0.f,-97.f),FRotator(0.f,-90.f,0.f));

	//스프링암 세팅
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->bDoCollisionTest = false;
	SpringArm->TargetArmLength = 800.f;
	SpringArm->SocketOffset = FVector(0.f,0.f,75.f);
	SpringArm->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	//카메라 세팅
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//캐릭터 무브먼트 세팅
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); 
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
	JumpMaxCount = 2;

	//캡슐컴포넌트 세팅
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
}

// Called when the game starts or when spawned
void APlayCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

// Called every frame
void APlayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayCharacter::StopJumping);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayCharacter::Run);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayCharacter::StopRunning);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayCharacter::LeftRight);
}

void APlayCharacter::LeftRight(float Value)
{
	AddMovementInput(FVector(0.f,-1.f,0.f),Value);
}

void APlayCharacter::Run()
{
	GetCharacterMovement()->MaxWalkSpeed = 1000.f;
}

void APlayCharacter::StopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

void APlayCharacter::Jump()
{
	if(GetCharacterMovement()->IsFalling())
		GetCharacterMovement()->JumpZVelocity = 800.f;
	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}

void APlayCharacter::StopJumping()
{
	bPressedJump = false;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	ResetJumpState();
}
