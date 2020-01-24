#include "Item.h"

// Getters and Setters
// Getters
std::string const& Item::getName()
{
	return m_name;
}

int Item::getStackQuantity()
{
	return m_stackQuantity;
}

int Item::getGoldValue()
{
	return m_goldValue;
}

int Item::getInventorySlot()
{
	return m_inventorySlot;
}

// Setters
void Item::setName(std::string name)
{
	m_name = name;
}

void Item::setStackQuantity(int stackQuantity)
{
	m_stackQuantity = stackQuantity;
}

void Item::setGoldValue(int goldValue)
{
	m_goldValue = goldValue;
}

void Item::setInventorySlot(int inventorySlot)
{
	m_inventorySlot = inventorySlot;
}