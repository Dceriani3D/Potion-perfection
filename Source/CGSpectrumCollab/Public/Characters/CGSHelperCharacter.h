// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CGSBaseCharacter.h"
#include "CGSHelperCharacter.generated.h"

/**
 *
 */
UCLASS()
class CGSPECTRUMCOLLAB_API ACGSHelperCharacter : public ACGSBaseCharacter
{
	GENERATED_BODY()

public:

	ACGSHelperCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Helper Character")
	bool bIsSelected = false;

protected:

	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

	virtual void OnSelected();
	virtual void OnDeSelected();
};