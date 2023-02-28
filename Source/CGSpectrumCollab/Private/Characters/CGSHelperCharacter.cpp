// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CGSHelperCharacter.h"

#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Core/CGSPlayerController.h"

DEFINE_LOG_CATEGORY_STATIC(LogACGSHelperCharacter, All, All);

ACGSHelperCharacter::ACGSHelperCharacter() {}

void ACGSHelperCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACGSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogACGSHelperCharacter, Fatal, TEXT("The PlayerController needs to be a ACGSPlayerController class !!"));
		return;
	}

	PlayerController->SetHelperAction(this, EHelperAction::None);
}

void ACGSHelperCharacter::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);

	if (ButtonPressed == EKeys::LeftMouseButton)
	{
		PlayerController->ClearHelperSelection();
		PlayerController->AddHelperToSelection(this);
	}
}

bool ACGSHelperCharacter::IncreaseLevel()
{
	if (Level < 4)
	{
		Level++;
		return true;
	}

	return false;
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