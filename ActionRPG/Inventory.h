#pragma once
#include "Item.h"
#include "InventoryConstants.h"

class Inventory {
private:

	// Max number of items in the inventory
	int m_maxSize;

	// Number of gold the player currently has
	int m_gold;

	// Flag for inventory full
	bool m_isFull;
	
	// Vector representation of the inventory
	std::vector<Item *> *m_itemsVec;

	// Map representation of the inventory (for quick lookup)
	std::map<Item *, int> *m_itemsMap;

public:
	Inventory();
	~Inventory();

	void addItem(Item *item);
	void removeItem(Item *item);

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