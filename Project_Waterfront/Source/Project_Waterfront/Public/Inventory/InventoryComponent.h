// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory/ItemBase.h"
#include "InventorySlot.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class PROJECT_WATERFRONT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadOnly)
	TArray<UInventorySlot*> itemArray;
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(AItemBase* item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItemFromSlot(UInventorySlot* item, int amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(AItemBase* item, int amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int GetItemCount(AItemBase* item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<UInventorySlot*> GetItemSlotsOfType(AItemBase* item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AttachToInterface();

};
