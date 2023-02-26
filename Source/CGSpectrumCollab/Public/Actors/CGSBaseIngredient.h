// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGSBaseIngredient.generated.h"

class UPointLightComponent;
class UCapsuleComponent;
class ACGSPlayerController;
enum class EHelperAction : uint8;

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSBaseIngredient : public AActor
{
	GENERATED_BODY()

public:

	// Sets default values for this actor's properties
	ACGSBaseIngredient();
	
	UFUNCTION(BlueprintCallable, Category = "Ingredient")
	FORCEINLINE bool IsDisabled() const
	{
		return bIsDisabled;
	}

	UFUNCTION(BlueprintCallable, Category = "Ingredient")
	FORCEINLINE float GetIngredientMaxAmount() const
	{
		return IngredientLevel * IngredientLevel * IngredientBaseAmount + IngredientBaseAmount;
	}

protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UPointLightComponent> PointLightComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	EHelperAction HelperInteractAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	float NavigationRadius = 100.0f;
	
	UPROPERTY(EditAnywhere, Category = "Ingredient")
	float IngredientBaseAmount = 30.0f;
	
	UPROPERTY(EditAnywhere, Category = "Ingredient")
	int IngredientLevel = 1;

	UFUNCTION(BlueprintCallable, Category = "Ingredient")
	void TakeIngredient(float Amount);

	virtual void BeginPlay() override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
	virtual void NotifyActorBeginCursorOver() override;
	virtual void NotifyActorEndCursorOver() override;

private:

	TObjectPtr<ACGSPlayerController> PlayerController;
	bool bIsDisabled = false;
	float CurrentDurability = FLT_MIN;
};