// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CGSBaseCharacter.h"

// Sets default values
ACGSBaseCharacter::ACGSBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACGSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACGSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}