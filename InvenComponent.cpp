// Fill out your copyright notice in the Description page of Project Settings.


#include "InvenComponent.h"
#include "Item.h"

// Sets default values for this component's properties
UInvenComponent::UInvenComponent()
{
}


// Called when the game starts
void UInvenComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : DefaultItems) {
		AddItem(Item);
	}
	
}

bool UInvenComponent::AddItem(UItem* Item)
{
	Item->OwningInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	//Inventory updated so call delegate
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInvenComponent::RemoveItem(UItem* Item)
{
	if (Item) {
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);

		OnInventoryUpdated.Broadcast();

		return true;
	}
	return false;
}


