#pragma once
#include "Item.h"
#include "PlayerConstants.h"

// Abstract class extended from Item, which is extended by wearable item classes (armor, weapons)
class WearableItem : Item {
private:
	// The slot in which this armor piece can be equipped
	int m_equipSlot;

	// Current durability of the item
	int m_durability;

	// Class requirement for the armor piece
	// TODO: Add "All" to class enum
	PlayerConstants::PlayerClass m_classRequirement;

	// TODO: Add more data here as necessary

public:
	// Getters and Setters
	// Getters
	int getEquipSlot();
	int getDurability();
	PlayerConstants::PlayerClass getClassRequirement();

	// Setters
	void setEquipSlot(int equipSlot);
	void setDurability(int durability);
	void setClassRequirement(PlayerConstants::PlayerClass classRequirement);

};
