// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLERUN_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector platformVelocity = FVector(300, 0, 0);

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float maxDist = 600;

	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FRotator rotationVelocity = FRotator(0, 0, 0);

	FVector startPosition;

	void movePlatform(float DeltaTime);
	void rotatePlatform(float DeltaTime);
	//const functions cannot modify class, cannot call non-const functions
	float getDistanceMoved(FVector currentPosition) const;
};
