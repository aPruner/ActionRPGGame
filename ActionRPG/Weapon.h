#pragma once
#include "EquipableItem.h"

class Weapon : public EquipableItem {
protected:
	// Base Attack damage
	int m_baseAttackDmg;

	// TODO: Add more data here as necessary

public:
	Weapon(std::string const& name);
	~Weapon();

	// Getters and Setters
	// Getters
	int getBaseAttackDmg();

	// Setters
	void setBaseAttackDmg(int baseAttackDmg);
};