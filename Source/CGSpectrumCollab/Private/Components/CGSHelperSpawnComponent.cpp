// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CGSHelperSpawnComponent.h"

#include "TimerManager.h"
#include "Characters/CGSHelperCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogUCGSHelperSpawnComponent, All, All);

// Sets default values for this component's properties
UCGSHelperSpawnComponent::UCGSHelperSpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UCGSHelperSpawnComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnBox = GetOwner()->FindComponentByClass<UBoxComponent>();
	if (SpawnBox == nullptr)
	{
		UE_LOG(LogUCGSHelperSpawnComponent, Error, TEXT("Please add a UBoxComponent for spawning!!!"));
		return;
	}

	// Spawn default helpers
	int Repeat = 0;
	do
	{
		SpawnHelper();
		Repeat++;
	} while (Repeat < DefaultNumber);

	// Assign delegate
	if (WaitingForSpawn > 0.0f)
	{
		FTimerDelegate Delegate;
		FTimerHandle TimerHandle;
		Delegate.BindUFunction(this, "SpawnHelper");
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, Delegate, WaitingForSpawn, true);
	}
}

void UCGSHelperSpawnComponent::SpawnHelper()
{
	if (!GetWorld() || SpawnBox == nullptr) return;

	const FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetOwner()->GetActorTransform());

	FVector SpawnLocation = BoxBounds.Origin;
	SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
	SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();

	GetWorld()->SpawnActor(HelperClass, &SpawnLocation);
}