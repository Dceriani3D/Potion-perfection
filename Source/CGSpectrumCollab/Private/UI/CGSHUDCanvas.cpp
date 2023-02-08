// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CGSHUDCanvas.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"

void ACGSHUDCanvas::StartSelection()
{
	SetMousePosition(MouseStart);
	bIsDrawing = true;
}

void ACGSHUDCanvas::StopSelection()
{
	bIsDrawing = false;
}

void ACGSHUDCanvas::DrawHUD()
{
	Super::DrawHUD();

	if (bIsDrawing)
	{
		SetMousePosition(MouseEnd);
		DrawRect(SelectionColor, MouseStart.X, MouseStart.Y, MouseEnd.X, MouseEnd.Y);
	}
}

void ACGSHUDCanvas::SetMousePosition(FVector2D& Position)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		UWidgetLayoutLibrary::GetMousePositionScaledByDPI(PlayerController, Position.X, Position.Y);
	}
}