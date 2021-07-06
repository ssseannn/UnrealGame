// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class MYFIRSTSIDEPROJECT_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere, Category = "Actor Mesh Component", BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh; 
	//make a pointer to a static mesh because pointers are more efficient
	//makes the static mesh actually usable in the editor, uproperty adds the thing into the scope of the cleaner that clears useless things during the program
	//it is called a component because it is a part of a blue print
	//a blueprint can have multiple components but it starts with one defalut scene root
	//the default scene root is like the point everything is based around
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Vectors")
	FVector InitialLocation;
	//location used by set actor location when begin play is called

	UPROPERTY(BlueprintReadWrite, Category = "Floater Vectors", VisibleInstanceOnly)
	FVector PlacedLocation;
	//location of actor when dragged in from editor

	UPROPERTY(BlueprintReadOnly, Category = "Floater Vectors", VisibleDefaultsOnly)
	FVector WorldOrigin;

	UPROPERTY(BlueprintReadOnly, Category = "Floater Vectors", EditAnywhere)
	FVector InitialDirection;

	UPROPERTY(BlueprintReadOnly, Category = "Floater Vectors", EditAnywhere)
	bool bShouldFloat;

	UPROPERTY(BlueprintReadOnly, Category = "Floater Vectors", EditAnywhere)
	bool bShouldBounceFloat;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Floater Vectors") 
	bool bInitializeFloaterLocations;*/
	//no semi colon

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Vectors")
	bool bInitializeFloaterLocations;

private:
	long int counter = 300;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
