#pragma once
#include "EquipableItem.h"

class Armor : public EquipableItem {
private:
	// Defense value of the armor piece
	int m_baseArmorRating;

	// TODO: Add more data here as necessary

public:
	Armor(std::string const& name);
	~Armor();

	// Getters and Setters
	// Getters
	int getBaseArmorRating();

	// Setters
	void setBaseArmorRating(int armorRating);
};