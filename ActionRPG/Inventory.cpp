#include "Inventory.h"

Inventory::Inventory()
{
	m_maxSize = InventoryConstants::c_defaultMaxSize;
	m_gold = InventoryConstants::c_defaultStartingGold;
	m_isFull = false;
	m_isEmpty = true;
	m_freeSlots = m_maxSize;

	// TODO: Maybe init and add starting items here

	// Initialize Inventory data structures
	m_itemsVec = new std::vector<Item *>();
	m_itemsMap = new std::map<std::string, int>();
}

Inventory::~Inventory()
{
}

int Inventory::checkStackQuantities(Item* item, int currentItemStackQuantity)
{
	return 0;
}

bool Inventory::addItem(Item *item)
{
	// For now, just return false if the inventory is full. Deal with stacks later once inventory works for unstackable items
	// In other words, assume every stackQuantity and maxStackQuantity are both 1 for simplicity
	if (m_isFull)
	{
		return false;
	}

	auto it = m_itemsMap->find(item->getName());

	// For now, this logic will be the same in either branch of the if statement, as stack quantities are not relevant yet
	// Once stack quantities come into play, this logic will have to change for the else branch, as stacks of items can be 
	// added to existing stacks if they are small enough (without taking up new free slot)
	if (it == m_itemsMap->end())
	{
		std::pair<std::string, int> newItemPair(item->getName(), item->getStackQuantity());
		m_itemsMap->insert(newItemPair);
		m_itemsVec->push_back(item);
		m_freeSlots--;
		if (m_freeSlots == 0 && m_itemsVec->size() == m_maxSize)
		{
			m_isFull = true;
		}
	}
	else
	{
		std::pair<std::string, int> newItemPair(item->getName(), item->getStackQuantity());
		m_itemsMap->insert(newItemPair);
		m_itemsVec->push_back(item);
		m_freeSlots--;
		if (m_freeSlots == 0 && m_itemsVec->size() == m_maxSize)
		{
			m_isFull = true;
		}
	}
	return true;
}

bool Inventory::removeItem(Item *item)
{
	if (m_isEmpty)
	{
		return false;
	}

	auto itMap = m_itemsMap->find(item->getName());
	if (itMap == m_itemsMap->end())
	{
		return false;
	}

	// TODO: implement logic for stackQuantities
	// For now, this method (as well as addItem) assumes that all items behave like EquipableItems (stackQuantity and maxStackQuantity will always be == 1)
	m_itemsMap->at(item->getName())--;
	if (m_itemsMap->at(item->getName()) == 0)
	{
		m_itemsMap->erase(item->getName());
	}
	
	auto itVec = std::find(m_itemsVec->begin(), m_itemsVec->end(), item);
	if (itVec != m_itemsVec->end())
	{
		m_itemsVec->erase(itVec);
	}
	return true;
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

bool Inventory::getIsEmpty()
{
	return m_isEmpty;
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

void Inventory::setIsEmpty(bool isEmpty)
{
	m_isEmpty = isEmpty;
}