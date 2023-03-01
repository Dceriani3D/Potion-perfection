// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CGSBaseIngredient.h"

#include "NavigationSystem.h"
#include "Characters/CGSHelperCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/PointLightComponent.h"
#include "Core/CGSConditionSubsystem.h"
#include "Core/CGSPlayerController.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogCGSBaseIngredient, All, All);

// Sets default values
ACGSBaseIngredient::ACGSBaseIngredient()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	CapsuleComponent->SetupAttachment(RootComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	MeshComponent->SetupAttachment(CapsuleComponent);

	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>("Point Light Component");
	PointLightComponent->SetupAttachment(MeshComponent);

	HelperInteractAction = EHelperAction::Collecting;
}

void ACGSBaseIngredient::TakeIngredient(const float Amount, ACGSHelperCharacter* Worker)
{
	CurrentDurability -= Amount;
	if (CurrentDurability <= 0.0f)
	{
		bIsDisabled = true;
		PointLightComponent->SetIntensity(0.0f);

		Worker->SetCurrentIngredient(this);
		Worker->SpawnBag();
	}
}

// Called when the game starts or when spawned
void ACGSBaseIngredient::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACGSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogCGSBaseIngredient, Fatal, TEXT("Cannot find ACGSPlayerController class !"));
		return;
	}

	CurrentDurability = GetIngredientMaxAmount();
	UCGSConditionSubsystem* ConditionSubsystem = GetWorld()->GetSubsystem<UCGSConditionSubsystem>();
	if (ConditionSubsystem)
	{
		ConditionSubsystem->AddNewCondition(this, NeededQuantity);
	}
}

void ACGSBaseIngredient::NotifyActorOnClicked(FKey ButtonPressed)
{
	if (bIsDisabled) return;
	Super::NotifyActorOnClicked(ButtonPressed);

	if (ButtonPressed == EKeys::RightMouseButton)
	{
		const TObjectPtr<UNavigationSystemV1> Navigation = UNavigationSystemV1::GetCurrent(GetWorld());
		if (Navigation)
		{
			for (ACGSHelperCharacter* Helper : PlayerController->GetAllSelectedHelpers())
			{
				FNavLocation TargetLocation;
				Navigation->GetRandomPointInNavigableRadius(GetActorLocation(), NavigationRadius, TargetLocation);
				PlayerController->MoveHelper(Helper, TargetLocation.Location);
				PlayerController->SetHelperAction(Helper, HelperInteractAction);
				PlayerController->SetHelperTarget(Helper, this);
			}
		}
		else
		{
			PlayerController->MoveSelectedHelpers(GetActorLocation());
		}
	}
}

void ACGSBaseIngredient::NotifyActorBeginCursorOver()
{
	if (bIsDisabled) return;
	Super::NotifyActorBeginCursorOver();

	MeshComponent->bRenderCustomDepth = true;
	MeshComponent->CustomDepthStencilValue = 1;
	MarkComponentsRenderStateDirty();
}

void ACGSBaseIngredient::NotifyActorEndCursorOver()
{
	if (bIsDisabled) return;
	Super::NotifyActorEndCursorOver();

	MeshComponent->bRenderCustomDepth = false;
	MeshComponent->CustomDepthStencilValue = 0;
	MarkComponentsRenderStateDirty();
}