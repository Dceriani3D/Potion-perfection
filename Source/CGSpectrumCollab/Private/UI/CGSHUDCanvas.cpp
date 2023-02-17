// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CGSHUDCanvas.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Characters/CGSHelperCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Core/CGSPlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(LogACGSHUDCanvas, All, All);

void ACGSHUDCanvas::StartSelection()
{
	MouseStart = GetMousePosition();
	bIsDrawing = true;
}

void ACGSHUDCanvas::StopSelection()
{
	bIsDrawing = false;

	UE_LOG(LogACGSHUDCanvas, Display, TEXT("Selection Count: %d"), SelectedHelpers.Num());
	if (SelectedHelpers.Num() == 0)
	{
		FHitResult HitResult;
		PlayerController->GetHitResultUnderCursorByChannel(InteractableChannel, true, HitResult);
		if (!HitResult.GetActor())
		{
			PlayerController->ClearHelperSelection();
		}
		return;
	}

	PlayerController->ClearHelperSelection();
	for (auto HelperActor : SelectedHelpers)
	{
		ACGSHelperCharacter* Helper = Cast<ACGSHelperCharacter>(HelperActor);
		if (Helper)
		{
			PlayerController->AddHelperToSelection(Helper);
		}
	}
	SelectedHelpers.Empty();
}

void ACGSHUDCanvas::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACGSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogACGSHUDCanvas, Fatal, TEXT("Cannot find the ACGSPlayerController !!"));
	}
}

void ACGSHUDCanvas::DrawHUD()
{
	Super::DrawHUD();

	if (bIsDrawing)
	{
		MouseEnd = GetMousePosition();
		DrawRect(SelectionColor, MouseStart.X, MouseStart.Y, MouseEnd.X - MouseStart.X, MouseEnd.Y - MouseStart.Y);

		if (FVector2d::Distance(MouseStart, MouseEnd) > SelectionRange)
		{
			GetActorsInSelectionRectangle(HelperCharClass, MouseStart, MouseEnd, SelectedHelpers, false, true);
		}
	}
}

FVector2D ACGSHUDCanvas::GetMousePosition()
{
	return UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld()) * UWidgetLayoutLibrary::GetViewportScale(GetWorld());
}