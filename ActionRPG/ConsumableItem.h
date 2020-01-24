#pragma once
#include "Item.h"

class ConsumableItem : Item {
private:
	// Consumable equip slot for this consumable
	int m_consumableEquipSlot;

	// Amount of whatever resource this consumable restores
	int m_amountRestored;

	// Time to restore the amount of a resource above in MS
	float m_timeToRestore;

	// TODO: Add more data here as necessary

public:
	// Getters and Setters
	// Getters
	int getConsumableEquipSlot();
	int getAmountRestored();
	float getTimeToRestore();

	// Setters
	void setConsumableEquipSlot(int consumableEquipSlot);
	void setAmountRestored(int amountRestored);
	void setTimeToRestore(float timeToRestore);
};