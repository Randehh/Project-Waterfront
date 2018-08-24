// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Inventory/ItemBase.h"
#include "CraftingRecipe.generated.h"

UCLASS()
class PROJECT_WATERFRONT_API UCraftingRecipe : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		FString recipeName;

	UPROPERTY(EditDefaultsOnly)
		TArray<UBlueprint*> resultItems;

	UPROPERTY(EditDefaultsOnly)
	TArray<UBlueprint*> requiredItems;

private:

	void CheckItemList(TArray<UBlueprint*> &list);
	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);
};
