// Fill out your copyright notice in the Description page of Project Settings.

#include "CraftingRecipe.h"
#include "Engine/Blueprint.h"

void UCraftingRecipe::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) {
	CheckItemList(requiredItems);
	CheckItemList(resultItems);
}

void UCraftingRecipe::CheckItemList(TArray<UBlueprint*> &list) {
	for (int i = list.Num() - 1; i >= 0; i--) {
		UBlueprint* bp = list[i];
		if (bp == nullptr) continue;
		if (bp->ParentClass->IsChildOf<AItemBase>()) continue;
		list.Remove(bp);
	}
}