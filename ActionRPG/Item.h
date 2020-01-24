#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive wearable, consumable, and other game items
class Item {
private:
	// Item name
	std::string m_name;

	// Quantity for stacks of items
	int m_stackQuantity;

	// Monetary value in gold
	int m_goldValue;

	// Inventory slot in the player's inventory
	int m_inventorySlot;

	// Icon representing the weapon in the inventory
	sf::Sprite m_iconSprite;

	// TODO: Add more stuff here as necessary
	
public:
	// Getters and Setters
	// Getters
	std::string const& getName();
	int getStackQuantity();
	int getGoldValue();
	int getInventorySlot();

	// Setters
	void setName(std::string name);
	void setStackQuantity(int stackQuantity);
	void setGoldValue(int goldValue);
	void setInventorySlot(int inventorySlot);
};