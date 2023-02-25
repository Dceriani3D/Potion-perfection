// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/NavLinkProxy.h"
#include "CGSNavLinkProxy.generated.h"

class ACGSBaseCharacter;

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSNavLinkProxy : public ANavLinkProxy
{
	GENERATED_BODY()

public:

	ACGSNavLinkProxy();

protected:

	UFUNCTION()
	void OnActorReachSmartLink(AActor* MovingActor, const FVector& DestinationPoint);

	virtual void BeginPlay() override;
};