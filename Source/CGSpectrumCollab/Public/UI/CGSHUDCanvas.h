// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CGSHUDCanvas.generated.h"

/**
 *
 */
UCLASS()
class CGSPECTRUMCOLLAB_API ACGSHUDCanvas : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Player Action")
	void StartSelection();
	
	UFUNCTION(BlueprintCallable, Category = "Player Action")
	void StopSelection();

protected:

	virtual void DrawHUD() override;

	UFUNCTION(BlueprintCallable, Category = "Utilities")
	FVector2D GetMousePosition();

	UPROPERTY(EditDefaultsOnly, Category = "Player Action HUD")
	FColor SelectionColor;

private:

	FVector2D MouseStart;
	FVector2D MouseEnd;
	
	bool bIsDrawing = false;
};