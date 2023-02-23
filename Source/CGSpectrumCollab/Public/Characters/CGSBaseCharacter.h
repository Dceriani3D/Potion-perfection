// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CGSBaseCharacter.generated.h"

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	// Sets default values for this character's properties
	ACGSBaseCharacter();

	UPROPERTY(EditAnywhere, Category = "Character Movement")
	float JumpDuration = 2.0f;
	
	UPROPERTY(EditAnywhere, Category = "Character Movement")
	float Gravity = 987.0f;

	UFUNCTION(BlueprintCallable, Category = "Character")
	virtual void HandleReachNavLink(const FVector& Destination);

private:

	FVector CalculateVelocity(const FVector& Start, const FVector& End, const float Duration);
};