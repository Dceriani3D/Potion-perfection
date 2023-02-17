// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSPlayerController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/CGSHelperCharacter.h"

ACGSPlayerController::ACGSPlayerController() {}

void ACGSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Common settings
	bShowMouseCursor = true;
	bEnableClickEvents = true;

	// Input Mode settings
	FInputModeGameAndUI InputMode;
	InputMode.SetHideCursorDuringCapture(false);

	SetInputMode(InputMode);
}

void ACGSPlayerController::ProcessPlayerInput(const float DeltaTime, const bool bGamePaused)
{
	Super::ProcessPlayerInput(DeltaTime, bGamePaused);

	if (IsInputKeyDown(EKeys::RightMouseButton))
	{
		FHitResult HitResult;
		GetHitResultUnderCursorByChannel(TraceChannel, true, HitResult);
		if (HitResult.GetActor())
		{
			for (TObjectPtr<ACGSHelperCharacter> Helper : SelectedHelpers)
			{
				const TObjectPtr<UBlackboardComponent> Blackboard = UAIBlueprintHelperLibrary::GetBlackboard(Helper);
				Blackboard->SetValueAsVector(BlackBoardTargetLocation, HitResult.ImpactPoint);
			}
		}
	}
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