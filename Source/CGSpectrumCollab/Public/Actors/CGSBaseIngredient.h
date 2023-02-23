// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGSBaseIngredient.generated.h"

class ACGSPlayerController;
enum class EHelperAction : uint8;

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSBaseIngredient : public AActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	ACGSBaseIngredient();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	EHelperAction HelperInteractAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	float NavigationRadius = 100.0f;

private:

	TObjectPtr<ACGSPlayerController> PlayerController;
};