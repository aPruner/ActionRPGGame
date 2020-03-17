#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

// Getters and Setters
// Getters
int Weapon::getBaseAttackDmg()
{
	return m_baseAttackDmg;
}

// Setters
void Weapon::setBaseAttackDmg(int baseAttackDmg)
{
	m_baseAttackDmg = baseAttackDmg;
}