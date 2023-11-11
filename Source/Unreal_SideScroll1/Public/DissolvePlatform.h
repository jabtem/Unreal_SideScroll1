// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DissolvePlatform.generated.h"

UCLASS()
class UNREAL_SIDESCROLL1_API ADissolvePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADissolvePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DissolveObject(float DeltaTime);

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	float Time;
	UPROPERTY(VisibleAnywhere)
	bool bIsTimeStop;
	UPROPERTY(VisibleAnywhere)
	bool bIsActive;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Dissolve, Meta=(AllowPrivateAccess=true))
	float ActiveTime;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Dissolve, Meta=(AllowPrivateAccess=true))
	float DeActiveTime;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Dissolve, Meta=(AllowPrivateAccess=true))
	float DissolveAmount;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Dissolve, Meta=(AllowPrivateAccess=true))
	float DissolveSpeed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Dissolve, Meta=(AllowPrivateAccess=true))
	bool bIsDissolve;
};
