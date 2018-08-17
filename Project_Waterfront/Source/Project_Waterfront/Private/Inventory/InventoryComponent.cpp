// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::AddItem(AItemBase * item) {
	int amount = item->itemCountOnPickup;
	TArray<UInventorySlot*> itemSlots = GetItemSlotsOfType(item);
	for (int i = 0; i < itemSlots.Num(); i++) {
		UInventorySlot* itemSlot = itemSlots[i];

		int currentStackSize = itemSlot->stackSize;
		currentStackSize += amount;
		if (currentStackSize > item->stackSize) {
			amount = currentStackSize - item->stackSize;
			currentStackSize = item->stackSize;
		} else {
			amount = 0;
		}

		itemSlot->stackSize = currentStackSize;
	}

	while (amount > 0) {
		int stackAmount = amount;
		if (stackAmount > item->stackSize) {
			amount -= item->stackSize;
			stackAmount = item->stackSize;
		} else {
			amount = 0;
		}

		UInventorySlot* itemSlot = NewObject<UInventorySlot>();
		itemSlot->itemType = item;
		itemSlot->stackSize = stackAmount;
		itemArray.Add(itemSlot);
	}
}

bool UInventoryComponent::RemoveItemFromSlot(UInventorySlot* item, int amount) {
	if (item->stackSize < amount) {
		return false;
	}

	item->stackSize -= amount;
	if (item->stackSize <= 0) {
		itemArray.Remove(item);
	}
	return true;
}

bool UInventoryComponent::RemoveItem(AItemBase* item, int amount) {
	int inInventory = GetItemCount(item);
	if (inInventory < amount) return false;

	TArray<UInventorySlot*> itemSlots = GetItemSlotsOfType(item);
	for (int i = itemSlots.Num() - 1; i >= 0; i++) {
		UInventorySlot* itemSlot = itemSlots[i];
		int toRemove = FMath::Clamp<int>(amount, 0, itemSlot->stackSize);
		RemoveItemFromSlot(itemSlot, toRemove);
		amount -= toRemove;
		if (amount <= 0) break;
	}

	return false;
}

int UInventoryComponent::GetItemCount(AItemBase* item) {
	TArray<UInventorySlot*> itemSlots = GetItemSlotsOfType(item);
	int totalCount = 0;
	for (int i = 0; i < itemSlots.Num(); i++) {
		UInventorySlot* itemSlot = itemSlots[i];
		totalCount += itemSlot->stackSize;
	}
	return totalCount;
}

TArray<UInventorySlot*> UInventoryComponent::GetItemSlotsOfType(AItemBase* item) {
	TArray<UInventorySlot*> itemsOfType;
	for (int i = 0; i < itemArray.Num(); i++) {
		UInventorySlot* itemSlot = itemArray[i];
		if (itemSlot->itemType == item) continue;
		itemsOfType.Add(itemSlot);
	}
	return itemsOfType;
}

void UInventoryComponent::AttachToInterface() {
}

