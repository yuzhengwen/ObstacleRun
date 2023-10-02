// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startPosition = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Message"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	movePlatform(DeltaTime);
	rotatePlatform(DeltaTime);
}

void AMovingPlatform::movePlatform(float DeltaTime)
{
	FVector currentPosition = GetActorLocation();
	currentPosition = currentPosition + (platformVelocity * DeltaTime);
	SetActorLocation(currentPosition);

	if (getDistanceMoved(currentPosition) > maxDist) {
		FVector direction = platformVelocity.GetSafeNormal();
		startPosition = startPosition + direction * maxDist;
		SetActorLocation(startPosition);
		platformVelocity = -platformVelocity;
	}
}

void AMovingPlatform::rotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotationVelocity * DeltaTime);
}

float AMovingPlatform::getDistanceMoved(FVector currentPosition) const
{
	return FVector::Dist(currentPosition, startPosition);
}

