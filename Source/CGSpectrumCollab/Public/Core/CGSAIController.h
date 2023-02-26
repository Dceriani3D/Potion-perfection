// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CGSAIController.generated.h"

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSAIController : public AAIController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "AI Controller")
	FORCEINLINE FVector GetCauldronLocation() const
	{
		return Cauldron->GetActorLocation();
	}

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI Controller")
	TSubclassOf<AActor> CauldronClass;

	UPROPERTY(EditDefaultsOnly, Category = "AI Controller")
	TObjectPtr<UBehaviorTree> BehaviorTree;

private:

	TObjectPtr<AActor> Cauldron;
};