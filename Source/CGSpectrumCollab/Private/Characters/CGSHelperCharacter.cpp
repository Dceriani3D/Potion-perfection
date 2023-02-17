// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CGSHelperCharacter.h"

#include "Core/CGSPlayerController.h"
#include "Kismet/GameplayStatics.h"

ACGSHelperCharacter::ACGSHelperCharacter() {}

void ACGSHelperCharacter::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);

	if (ButtonPressed == EKeys::LeftMouseButton)
	{
		ACGSPlayerController* PlayerController = Cast<ACGSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		if (!PlayerController)
		{
			UE_LOG(LogTemp, Error, TEXT("The PlayerController needs to be a ACGSPlayerController class !!"));
			return;
		}

		if (!bIsSelected)
		{
			PlayerController->ClearHelperSelection();
			PlayerController->AddHelperToSelection(this);
		}
	}
}

void ACGSHelperCharacter::OnSelected()
{
	bIsSelected = true;

	this->GetMesh()->bRenderCustomDepth = true;
	this->GetMesh()->CustomDepthStencilValue = 2;
	MarkComponentsRenderStateDirty();
}

void ACGSHelperCharacter::OnDeSelected()
{
	bIsSelected = false;

	this->GetMesh()->bRenderCustomDepth = false;
	this->GetMesh()->CustomDepthStencilValue = 0;
	MarkComponentsRenderStateDirty();
}