// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CGSPlayerController.generated.h"

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ACGSPlayerController();

protected:

	virtual void BeginPlay() override;
};