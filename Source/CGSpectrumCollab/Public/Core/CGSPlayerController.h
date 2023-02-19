// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CGSPlayerController.generated.h"

class ACGSHelperCharacter;
enum class EHelperAction : uint8;

UCLASS()
class CGSPECTRUMCOLLAB_API ACGSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ACGSPlayerController();

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	FORCEINLINE TArray<ACGSHelperCharacter*> GetAllSelectedHelpers()
	{
		return SelectedHelpers;
	}
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void AddHelperToSelection(ACGSHelperCharacter* NewHelper);

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void RemoveHelperFromSelection(ACGSHelperCharacter* HelperToRemove);

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void ClearHelperSelection();
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void MoveHelper(ACGSHelperCharacter* Helper, const FVector& TargetLocation);
	
	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void MoveSelectedHelpers(const FVector& TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Player Controller")
	void SetHelperAction(ACGSHelperCharacter* Helper, EHelperAction Action);
	
protected:

	UPROPERTY(VisibleAnywhere, Category = "Player Controller")
	TArray<TObjectPtr<ACGSHelperCharacter>> SelectedHelpers;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player Controller")
	TEnumAsByte<ETraceTypeQuery> TraceChannel;
	
	UPROPERTY(EditDefaultsOnly, Category = "Player Controller")
	FName BlackBoardTargetLocation;
	
	virtual void BeginPlay() override;
	virtual void ProcessPlayerInput(const float DeltaTime, const bool bGamePaused) override;
};