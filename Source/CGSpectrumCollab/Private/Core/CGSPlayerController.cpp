// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSPlayerController.h"

#include "Characters/CGSHelperCharacter.h"

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
	InputMode.SetHideCursorDuringCapture(false);

	SetInputMode(InputMode);
}

void ACGSPlayerController::AddHelperToSelection(ACGSHelperCharacter* NewHelper)
{
	SelectedHelpers.AddUnique(NewHelper);
	NewHelper->OnSelected();
}

void ACGSPlayerController::RemoveHelperFromSelection(ACGSHelperCharacter* HelperToRemove)
{
	SelectedHelpers.Remove(HelperToRemove);
	HelperToRemove->OnDeSelected();
}

void ACGSPlayerController::ClearHelperSelection()
{
	if (SelectedHelpers.Num() == 0) return;
	
	for (const TObjectPtr<ACGSHelperCharacter> Helper : SelectedHelpers)
	{
		if (Helper->bIsSelected)
		{
			Helper->OnDeSelected();
		}
	}
	SelectedHelpers.Empty();
}