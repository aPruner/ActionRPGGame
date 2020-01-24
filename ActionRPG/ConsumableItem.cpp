#include "ConsumableItem.h"

// Getters and Setters
// Getters
int ConsumableItem::getConsumableEquipSlot()
{
	return m_consumableEquipSlot;
}

int ConsumableItem::getAmountRestored()
{
	return m_amountRestored;
}

float ConsumableItem::getTimeToRestore()
{
	return m_timeToRestore;
}

// Setters
void ConsumableItem::setConsumableEquipSlot(int consumableEquipSlot)
{
	m_consumableEquipSlot = consumableEquipSlot;
}

void ConsumableItem::setAmountRestored(int amountRestored)
{
	m_amountRestored = amountRestored;
}

void ConsumableItem::setTimeToRestore(float timeToRestore)
{
	m_timeToRestore = timeToRestore;
}