#include "Item.h"

// Getters and Setters
// Getters
std::string const& Item::getName()
{
	return m_name;
}

bool Item::getIsStackable()
{
	return m_isStackable;
}

int Item::getStackQuantity()
{
	return m_stackQuantity;
}

int Item::getMaxStackQuantity()
{
	return m_maxStackQuantity;
}

int Item::getGoldValue()
{
	return m_goldValue;
}

int Item::getInventorySlot()
{
	return m_inventorySlot;
}

sf::Sprite Item::getPickupSprite()
{
	return m_pickupSprite;
}

// Setters
void Item::setName(std::string name)
{
	m_name = name;
}

void Item::setIsStackable(bool isStackable)
{
	m_isStackable = isStackable;
}

void Item::setStackQuantity(int stackQuantity)
{
	m_stackQuantity = stackQuantity;
}

void Item::setMaxStackQuantity(int maxStackQuantity)
{
	m_maxStackQuantity = maxStackQuantity;
}

void Item::setGoldValue(int goldValue)
{
	m_goldValue = goldValue;
}

void Item::setInventorySlot(int inventorySlot)
{
	m_inventorySlot = inventorySlot;
}

void Item::setPickupSprite(sf::Sprite pickupSprite)
{
	m_pickupSprite = pickupSprite;
}