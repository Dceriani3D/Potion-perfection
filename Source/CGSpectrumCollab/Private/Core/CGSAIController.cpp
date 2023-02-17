// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSAIController.h"

void ACGSAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
}