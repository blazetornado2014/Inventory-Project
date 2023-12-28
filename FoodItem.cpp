// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "InvenProjectCharacter.h"

UFoodItem::UFoodItem(){}

void UFoodItem::Use(class AInvenProjectCharacter* Character) {
	if (Character) {
		Character->PlayerHealth += 1.0f;
	}
}
