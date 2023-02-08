// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CGSMainCamera.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSMainCamera : public AActor
{
	GENERATED_BODY()

public:

	ACGSMainCamera();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
    TObjectPtr<USpringArmComponent> SpringArmComponent;
    
    UPROPERTY(VisibleAnywhere, Category = "Components")
    TObjectPtr<UCameraComponent> CameraComponent;
};