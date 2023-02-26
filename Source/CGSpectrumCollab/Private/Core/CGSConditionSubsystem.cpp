// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/CGSConditionSubsystem.h"

void UCGSConditionSubsystem::AddIngredient(ACGSBaseIngredient* Ingredient)
{
	for (FGameCondition GameCondition : Conditions)
	{
		if (GameCondition.Ingredient->GetClass() != Ingredient->GetClass())
			continue;

		GameCondition.CurrentAmount++;
		break;
	}
}

bool UCGSConditionSubsystem::CheckWinCondition()
{
	for (const FGameCondition GameCondition : Conditions)
	{
		if (GameCondition.NeededAmount != GameCondition.CurrentAmount)
		{
			return false;
		}
	}

	return true;
}