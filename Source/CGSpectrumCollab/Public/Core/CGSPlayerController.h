// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CGSPlayerController.generated.h"

class ACGSHelperCharacter;

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ACGSPlayerController();

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void AddHelperToSelection(ACGSHelperCharacter* NewHelper);

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void RemoveHelperFromSelection(ACGSHelperCharacter* HelperToRemove);
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Player Controller")
	TArray<TObjectPtr<ACGSHelperCharacter>> SelectedHelpers;
};