// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovePlatform.generated.h"

UCLASS()
class UNREAL_SIDESCROLL1_API AMovePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Meta=(AllowPrivateAccess=true))
	class UInterpToMovementComponent* InterpToMove;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MovePoint, Meta=(AllowPrivateAccess=true))
	FVector Start;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MovePoint, Meta=(AllowPrivateAccess=true))
	FVector End;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=MovePoint, Meta=(AllowPrivateAccess=true))
	float DurationTime;

};
