// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include <string>
#include <iostream>


// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh")); //specify object type in pointy brackets
	//remember to build

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f);
	InitialDirection = FVector(0.0f);

	bInitializeFloaterLocations = false; 
	bShouldFloat = false;
	bShouldBounceFloat = false;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	PlacedLocation = GetActorLocation();
	
	if(bInitializeFloaterLocations)
		SetActorLocation(InitialLocation); //FVectors are used for location in the xyz planes
	
	UE_LOG(LogTemp, Warning, TEXT("I just started running"));

	FHitResult HitResult;
	FVector LocalOffset = FVector(200.f, 0.0f, 0.0f);
	//AddActorLocalOffset(LocalOffset, true, &HitResult);

	FRotator Rotation = FRotator(0.0f);
	AddActorLocalRotation(Rotation);
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldBounceFloat)
	{
		if (bShouldBounceFloat && counter > 150)
		{
			counter -= 1;
			FHitResult HitResult; //AddACtorLocalOffset is asking for one
			AddActorLocalOffset(InitialDirection, false, &HitResult);//deltalocation is how much it wants to change every function call
		}
		else if (bShouldBounceFloat && counter <= 150)
		{
			counter -= 1;
			FHitResult HitResult;
			AddActorLocalOffset(-1*InitialDirection, false, &HitResult);
			if (counter == 0)
				counter = 300;
		}
	}
	else if (bShouldFloat)
	{
		if (bShouldFloat)
		{
			FHitResult HitResult; //AddACtorLocalOffset is asking for one

			AddActorLocalOffset(InitialDirection, true, &HitResult);//deltalocation is how much it wants to change every function call
			//second parameter is boolean telling whether or not to do a sweep, sweeping makes sure it doesn't clip thru anything even when physics simulation is off, kind of like simulate physics


			FVector HitLocation = HitResult.Location;

			UE_LOG(LogTemp, Warning, TEXT("Hit Location: X = %f, Y = %f, Z = %f"), HitLocation.X, HitLocation.Y, HitLocation.Z);
		}
	}
}

