// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/CGSBaseIngredient.h"
#include "Subsystems/WorldSubsystem.h"
#include "CGSConditionSubsystem.generated.h"

USTRUCT(BlueprintType)
struct FGameCondition
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Condition")
	TObjectPtr<ACGSBaseIngredient> Ingredient = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Condition")
	int NeededAmount = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Condition")
	int CurrentAmount = 0;
};

UCLASS()
class CGSPECTRUMCOLLAB_API UCGSConditionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Condition")
	TArray<FGameCondition> Conditions;

	UFUNCTION(BlueprintCallable, Category = "Game Condition")
	void AddIngredient(ACGSBaseIngredient* Ingredient);

	UFUNCTION(BlueprintCallable, Category = "Game Condition")
	bool CheckWinCondition();
};
