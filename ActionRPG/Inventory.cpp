#include "Inventory.h"

Inventory::Inventory()
{
	m_maxSize = InventoryConstants::c_defaultMaxSize;
	m_gold = InventoryConstants::c_defaultStartingGold;
	m_isFull = false;

	// TODO: Maybe init and add starting items here

	// Initialize Inventory data structures
	m_itemsVec = new std::vector<Item *>();
	m_itemsMap = new std::map<Item *, int>();
}

Inventory::~Inventory()
{
}

void Inventory::addItem(Item *item)
{

}

void Inventory::removeItem(Item *item)
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