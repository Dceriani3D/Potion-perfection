// Fill out your copyright notice in the Description page of Project Settings.

#include "AI/CGSNavLinkProxy.h"

#include "NavLinkCustomComponent.h"
#include "Characters/CGSBaseCharacter.h"

DEFINE_LOG_CATEGORY_STATIC(LogACGSNavLinkProxy, All, All)

ACGSNavLinkProxy::ACGSNavLinkProxy()
{
	bSmartLinkIsRelevant = true;

	UNavLinkCustomComponent* SmartLink = GetSmartLinkComp();
	SmartLink->SetEnabled(true);
	SmartLink->bNavigationRelevant = true;
}

void ACGSNavLinkProxy::BeginPlay()
{
	Super::BeginPlay();
	OnSmartLinkReached.AddDynamic(this, &ACGSNavLinkProxy::OnActorReachSmartLink);
}

void ACGSNavLinkProxy::OnActorReachSmartLink(AActor* MovingActor, const FVector& DestinationPoint)
{
	UE_LOG(LogACGSNavLinkProxy, Display, TEXT("Actor %s reach smart link !!"), *MovingActor->GetName());
		
	ACGSBaseCharacter* Character = Cast<ACGSBaseCharacter>(MovingActor);
	if (Character)
	{
		Character->HandleReachNavLink(DestinationPoint);
	}
}