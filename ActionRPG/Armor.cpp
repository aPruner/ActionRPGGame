#include "Armor.h"

Armor::Armor()
{

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