#include "Weapon.h"

Weapon::Weapon(std::string const& name)
{
	m_name = name;

	// TODO: Set baseAttackDmg and other necessary stuff
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