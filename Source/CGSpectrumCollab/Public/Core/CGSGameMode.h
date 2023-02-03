// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CGSGameMode.generated.h"

/**
 *
 */
UCLASS()
class CGSPECTRUMCOLLAB_API ACGSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	ACGSGameMode();

protected:

	virtual void BeginPlay() override;
};