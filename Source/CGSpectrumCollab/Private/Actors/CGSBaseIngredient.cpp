// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/CGSBaseIngredient.h"

#include "NavigationSystem.h"
#include "Characters/CGSHelperCharacter.h"
#include "Core/CGSPlayerController.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogCGSBaseIngredient, All, All);

// Sets default values
ACGSBaseIngredient::ACGSBaseIngredient()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component");
	MeshComponent->SetupAttachment(RootComponent);

	HelperInteractAction = EHelperAction::Collecting;
}

// Called when the game starts or when spawned
void ACGSBaseIngredient::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACGSPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!PlayerController)
	{
		UE_LOG(LogCGSBaseIngredient, Fatal, TEXT("Cannot find ACGSPlayerController class !"));
	}
}

void ACGSBaseIngredient::NotifyActorOnClicked(FKey ButtonPressed)
{
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
			}
		}
		else
		{
			PlayerController->MoveSelectedHelpers(GetActorLocation());
		}
	}
}