// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInventoryComponent::AddItem(AItemBase * item) {
	int amount = item->itemCountOnPickup;
	for (int i = 0; i < itemArray.Num(); i++) {
		FInventorySlot itemSlot = itemArray[i];
		if (!itemSlot.itemType.Equals(item->GetName())) continue;

		int currentStackSize = itemSlot.stackSize;
		currentStackSize += amount;
		if (currentStackSize > item->stackSize) {
			amount = currentStackSize - item->stackSize;
			currentStackSize = item->stackSize;
		} else {
			amount = 0;
		}

		itemSlot.stackSize = currentStackSize;
		itemArray[i] = itemSlot;
	}

	while (amount > 0) {
		int stackAmount = amount;
		if (stackAmount > item->stackSize) {
			amount -= item->stackSize;
			stackAmount = item->stackSize;
		} else {
			amount = 0;
		}

		FInventorySlot itemSlot;
		itemSlot.itemType = item->GetName();
		itemSlot.stackSize = stackAmount;
		itemArray.Add(itemSlot);
	}
}

void UInventoryComponent::RemoveItem(AItemBase* item) {

}

