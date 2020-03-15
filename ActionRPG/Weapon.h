#pragma once
#include "EquipableItem.h"

class Weapon : EquipableItem {
private:
	// Base Attack damage
	int m_baseAttackDmg;

	// TODO: Add more data here as necessary

public:
	Weapon();
	~Weapon();

	// Getters and Setters
	// Getters
	int getBaseAttackDmg();

	// Setters
	void setBaseAttackDmg(int baseAttackDmg);
};