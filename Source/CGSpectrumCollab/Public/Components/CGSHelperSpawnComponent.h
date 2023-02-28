// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "CGSHelperSpawnComponent.generated.h"

class ACGSHelperCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CGSPECTRUMCOLLAB_API UCGSHelperSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	// Sets default values for this component's properties
	UCGSHelperSpawnComponent();

	UFUNCTION(BlueprintCallable, Category = "Helper Spawner")
	void SpawnHelper();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Helper Spawner")
	TSubclassOf<ACGSHelperCharacter> HelperClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Helper Spawner")
	TObjectPtr<UBoxComponent> SpawnBox;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Helper Spawner")
	float WaitingForSpawn = 100.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Helper Spawner")
	int DefaultNumber = 3;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Helper Spawner")
	int MaxNumber = 6;
	
	virtual void BeginPlay() override;
};