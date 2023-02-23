// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CGSBaseCharacter.h"

// Sets default values
ACGSBaseCharacter::ACGSBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ACGSBaseCharacter::HandleReachNavLink(const FVector& Destination)
{
	const FVector Velocity = CalculateVelocity(GetActorLocation(), Destination, JumpDuration);
	LaunchCharacter(Velocity, true, true);
}

FVector ACGSBaseCharacter::CalculateVelocity(const FVector& Start, const FVector& End, const float Duration)
{
	const float X = (End.X - Start.X) / Duration;
	const float Y = (End.Y - Start.Y) / Duration;
	const float Z = (End.Z - (Start.Z + Duration * Duration * -0.5f * Gravity)) / Duration;
	return FVector(X, Y, Z);
}