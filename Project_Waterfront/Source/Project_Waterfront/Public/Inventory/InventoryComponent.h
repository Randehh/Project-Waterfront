// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory/ItemBase.h"
#include "InventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventorySlot {
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FString itemType;

	UPROPERTY(VisibleAnywhere)
	uint8 stackSize = 0;
};

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FInventorySlot> itemArray;
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(AItemBase* item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(AItemBase* item);

};
