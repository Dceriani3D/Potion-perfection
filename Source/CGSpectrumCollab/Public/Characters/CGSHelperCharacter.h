// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CGSBaseCharacter.h"
#include "CGSHelperCharacter.generated.h"

UENUM(BlueprintType)
enum class EHelperAction : uint8
{
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
	virtual void OnSelected();

	UFUNCTION(BlueprintCallable, Category = "Helper Character")
	virtual void OnDeSelected();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Helper Character")
	bool bIsSelected = false;

protected:

	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
};