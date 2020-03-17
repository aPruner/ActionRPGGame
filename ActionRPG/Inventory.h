#pragma once
#include "Item.h"
#include "InventoryConstants.h"

class Inventory {
private:

	// Max number of items in the inventory
	int m_maxSize;

	// Number of gold the player currently has
	int m_gold;

	// Number of free stack slots in the inventory
	int m_freeSlots;

	// Flag for inventory full (no free slots)
	bool m_isFull;
	
	// Vector representation of the inventory
	std::vector<Item *> *m_itemsVec;

	// Map representation of the inventory (for quick lookup), maps itemName->totalQuantity (all stack quantities summed together)
	std::map<std::string, int> *m_itemsMap;

	// Returns the amount of free space available if item were to be added to the Inventory
	// NOTE: Returns a negative value if the item would overflow the Inventory
	int checkStackQuantities(Item *item, int currentStackQuantity);

public:
	Inventory();
	~Inventory();

	// Adds an item to the inventory if there is a free slot
	// Returns true if adding the item succeeded, false if not
	// TODO: logic for stacks of items, for now, all items have a stackQuantity value of 1, and a maxStackQuantity value of 1
	bool addItem(Item *item);

	// Removes an item from the inventory if it exists
	// Returns true if removing the item succeeded, false if not
	// TODO: logic for stacks of items, for now, all items have a stackQuantity value of 1, and a maxStackQuantity value of 1
	bool removeItem(Item *item);

	// Getters and Setters
	// Getters
	int getMaxSize();
	int getGold();
	bool getIsFull();
	
	// Setters
	void setMaxSize(int maxSize);
	void setGold(int gold);
	void setIsFull(bool isFull);

};