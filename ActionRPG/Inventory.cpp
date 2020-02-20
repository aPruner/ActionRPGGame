#include "Inventory.h"

Inventory::Inventory()
{
	m_maxSize = InventoryConstants::c_defaultMaxSize;
	m_gold = InventoryConstants::c_defaultStartingGold;
	m_isFull = false;
}

Inventory::~Inventory()
{
}

// Getters and Setters
// Getters
int Inventory::getGold()
{
	return m_gold;
}

int Inventory::getMaxSize()
{
	return m_maxSize;
}

bool Inventory::getIsFull()
{
	return m_isFull;
}

// Setters
void Inventory::setGold(int gold)
{
	m_gold = gold;
}

void Inventory::setMaxSize(int maxSize)
{
	m_maxSize = maxSize;
}

void Inventory::setIsFull(bool isFull)
{
	m_isFull = isFull;
}