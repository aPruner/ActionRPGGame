#pragma once
#include "WearableItem.h"

class Weapon : WearableItem {
private:
	// Base Attack damage
	int m_baseAttackDmg;


public:
	Weapon();
	~Weapon();

	// Getters and Setters
	// Getters
	int getBaseAttackDmg();

	// Setters
	void setBaseAttackDmg(int baseAttackDmg);
};