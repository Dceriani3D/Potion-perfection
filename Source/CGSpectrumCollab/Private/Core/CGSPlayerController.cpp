// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSPlayerController.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

ACGSPlayerController::ACGSPlayerController() {}

void ACGSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AActor* MainCamera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	if (MainCamera)
	{
		SetViewTarget(MainCamera);
	}
}