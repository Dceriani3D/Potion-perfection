// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/CGSHUDCanvas.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"

void ACGSHUDCanvas::StartSelection()
{
	MouseStart = GetMousePosition();
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
		MouseEnd = GetMousePosition();
		DrawRect(SelectionColor, MouseStart.X, MouseStart.Y, MouseEnd.X - MouseStart.X, MouseEnd.Y - MouseStart.Y);
	}
}

FVector2D ACGSHUDCanvas::GetMousePosition()
{
	return UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld()) * UWidgetLayoutLibrary::GetViewportScale(GetWorld());
}
