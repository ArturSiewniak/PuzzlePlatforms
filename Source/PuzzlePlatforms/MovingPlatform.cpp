// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (HasAuthority()) 
	{
		FVector Location = GetActorLocation();
		Location += FVector(PlatformSpeed * DeltaSeconds, 0.f, 0.f);
		SetActorLocation(Location);
	}
	
}
