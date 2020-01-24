#include "WearableItem.h"

// Getters and Setters
// Getters
int WearableItem::getEquipSlot()
{
	return m_equipSlot;
}

int WearableItem::getDurability()
{
	return m_durability;
}

PlayerConstants::PlayerClass WearableItem::getClassRequirement()
{
	return m_classRequirement;
}

// Setters
void WearableItem::setEquipSlot(int equipSlot)
{
	m_equipSlot = equipSlot;
}

void WearableItem::setDurability(int durability)
{
	m_durability = durability;
}

void WearableItem::setClassRequirement(PlayerConstants::PlayerClass classRequirement)
{
	m_classRequirement = classRequirement;
}
