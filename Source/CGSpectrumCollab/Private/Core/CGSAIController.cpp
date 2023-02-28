// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSAIController.h"

#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogACGSAIController, All, All);

void ACGSAIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);

	Cauldron = UGameplayStatics::GetActorOfClass(GetWorld(), CauldronClass);
	if (!Cauldron)
	{
		UE_LOG(LogACGSAIController, Error, TEXT("Cannot find Cauldron !!"));
	}
}