// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CGSBaseCharacter.h"
#include "CGSHelperCharacter.generated.h"

class ACGSPlayerController;
class ACGSBaseIngredient;

UENUM(BlueprintType)
enum class EHelperAction : uint8
{
	None        UMETA(DisplayName = "None"),
	Collecting  UMETA(DisplayName = "Collecting Resource"),
	Hiding      UMETA(DisplayName = "Hiding From Cat"),
	Waiting     UMETA(DisplayName = "Waiting"),
};

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSHelperCharacter : public ACGSBaseCharacter
{
	GENERATED_BODY()

public:

	ACGSHelperCharacter();

	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	FORCEINLINE int GetStrength()
	{
		return Level * Strength + 1;
	}

	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual bool IncreaseLevel();
	
	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual void OnSelected();

	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual void OnDeSelected();
	
	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual void SpawnBag();

	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual void AddCurrentIngredientToCollection();
	
	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual void SetCurrentIngredient(ACGSBaseIngredient* Ingredient);

	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual ACGSBaseIngredient* GetCurrentIngredient();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Helper Character")
	bool bIsSelected = false;
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Helper Character")
	int Level = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Helper Character")
	int Strength = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Helper Character")
	ACGSBaseIngredient* CurrentIngredient = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Helper Character")
	TSubclassOf<AActor> BagClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Helper Character")
	FName BagSocketName = "BagSocket";

	virtual void BeginPlay() override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

private:

	TObjectPtr<ACGSPlayerController> PlayerController;
};