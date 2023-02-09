// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSPlayerController.h"

ACGSPlayerController::ACGSPlayerController()
{
	// Common settings
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}

void ACGSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Input Mode settings
	FInputModeGameAndUI InputMode;
	//InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetHideCursorDuringCapture(false);

	SetInputMode(InputMode);
}