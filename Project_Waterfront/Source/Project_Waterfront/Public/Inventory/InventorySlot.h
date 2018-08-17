// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Inventory/ItemBase.h"
#include "InventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class UInventorySlot : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	AItemBase* itemType;

	UPROPERTY(BlueprintReadOnly)
	uint8 stackSize = 0;
	
};
