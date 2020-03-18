#include "Inventory.h"
#include "Weapon.h"

Inventory::Inventory()
{
	m_maxSize = InventoryConstants::c_defaultMaxSize;
	m_gold = InventoryConstants::c_defaultStartingGold;
	m_isFull = false;
	m_freeSlots = m_maxSize;

	// Initialize Inventory data structures
	m_itemsVec = new std::vector<Item *>();
	m_itemsMap = new std::map<std::string, int>();

	// TODO: Constants
	// Initialize the knife (first basic item in every inventory)
	Item *knife = new Weapon("knife");
}

Inventory::~Inventory()
{
}

// TODO: Implement this, and stacking system in general
int Inventory::checkStackQuantities(Item* item, int currentItemStackQuantity)
{
	return 0;
}

bool Inventory::addItem(Item *item)
{
	// For now, just return false if the inventory is full. Deal with stacks later once inventory works for unstackable items
	// In other words, assume every stackQuantity and maxStackQuantity are both 1 for simplicity
	if (m_freeSlots == 0)
	{
		// Inventory is full if there are no free slots
		return false;
	}

	auto it = m_itemsMap->find(item->getName());

	// TODO: Read below comment and implement stacking system
	// For now, this logic will be the same in either branch of the if statement, as stack quantities are not relevant yet
	// Once stack quantities come into play, this logic will have to change for the else branch, as stacks of items can be 
	// added to existing stacks if they are small enough (without taking up new free slot)
	if (it == m_itemsMap->end())
	{
		std::pair<std::string, int> newItemPair(item->getName(), item->getStackQuantity());
		m_itemsMap->insert(newItemPair);
		m_itemsVec->push_back(item);
		m_freeSlots--;
		if (m_freeSlots == 0)
		{
			setIsFull(true);
		}
	}
	else
	{
		std::pair<std::string, int> newItemPair(item->getName(), item->getStackQuantity());
		m_itemsMap->insert(newItemPair);
		m_itemsVec->push_back(item);
		m_freeSlots--;
		if (m_freeSlots == 0)
		{
			setIsFull(true);
		}
	}
	return true;
}

bool Inventory::removeItem(Item *item)
{
	if (m_freeSlots == m_maxSize)
	{
		// Inventory is empty, nothing can be removed
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

	// After removing an item, the inventory will never be full
	m_freeSlots++;
	setIsFull(false);
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