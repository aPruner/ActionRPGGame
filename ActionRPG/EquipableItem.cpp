#include "EquipableItem.h"

// Getters and Setters
// Getters
int EquipableItem::getEquipSlot()
{
	return m_equipSlot;
}

int EquipableItem::getDurability()
{
	return m_durability;
}

PlayerConstants::PlayerClass EquipableItem::getClassRequirement()
{
	return m_classRequirement;
}

// Setters
void EquipableItem::setEquipSlot(int equipSlot)
{
	m_equipSlot = equipSlot;
}

void EquipableItem::setDurability(int durability)
{
	m_durability = durability;
}

void EquipableItem::setClassRequirement(PlayerConstants::PlayerClass classRequirement)
{
	m_classRequirement = classRequirement;
}
