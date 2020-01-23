#pragma once
#include "WearableItem.h"

class Armor : WearableItem {
private:
	// Defense value of the armor piece
	int m_baseArmorRating;

public:
	Armor();
	~Armor();

	// Getters and Setters
	// Getters
	int getBaseArmorRating();

	// Setters
	void setBaseArmorRating(int armorRating);
};