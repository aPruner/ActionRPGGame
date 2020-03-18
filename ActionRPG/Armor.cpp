#include "Armor.h"

Armor::Armor(std::string const& name)
{
	m_name = name;
	
	// TODO: Set baseArmorRating and other necessary stuff
}

Armor::~Armor()
{

}

// Getters and Setters
// Getters
int Armor::getBaseArmorRating()
{
	return m_baseArmorRating;
}

// Setters
void Armor::setBaseArmorRating(int armorRating)
{
	m_baseArmorRating = armorRating;
}