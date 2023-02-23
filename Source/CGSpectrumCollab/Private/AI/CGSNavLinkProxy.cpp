// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/CGSNavLinkProxy.h"

#include "NavLinkCustomComponent.h"
#include "Characters/CGSBaseCharacter.h"

ACGSNavLinkProxy::ACGSNavLinkProxy()
{
	bSmartLinkIsRelevant = true;

	UNavLinkCustomComponent* SmartLink = GetSmartLinkComp();
	SmartLink->SetEnabled(true);
	SmartLink->bNavigationRelevant = true;
}

void ACGSNavLinkProxy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	OnSmartLinkReached.AddDynamic(this, &ACGSNavLinkProxy::OnActorReachSmartLink);
}

void ACGSNavLinkProxy::OnActorReachSmartLink(AActor* MovingActor, const FVector& DestinationPoint)
{
	if (MovingActor->IsA(CharacterClass))
	{
		ACGSBaseCharacter* Character = Cast<ACGSBaseCharacter>(MovingActor);
		Character->HandleReachNavLink(DestinationPoint);
	}
}