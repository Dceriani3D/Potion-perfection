// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CGSAIController.generated.h"

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSAIController : public AAIController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI Controller")
	TObjectPtr<UBehaviorTree> BehaviorTree;
};