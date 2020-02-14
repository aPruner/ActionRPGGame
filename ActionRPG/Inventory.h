#pragma once
#include "Item.h"

class Inventory {
private:

	// Max number of items in the inventory
	int m_maxSize;
	
	// Vector representation of the inventory
	std::vector<Item> *m_items;


public:
	Inventory();
	~Inventory();

};