#pragma once
#include "Item.h"

class Inventory {
private:

	// Max number of items in the inventory
	int m_maxSize;

	// Number of gold the player currently has
	int m_gold;

	// Flag for inventory full
	bool m_isFull;
	
	// Vector representation of the inventory
	std::vector<Item> *m_items;

public:
	Inventory();
	~Inventory();

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