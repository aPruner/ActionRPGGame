#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive wearable, consumable, and other game items
class Item {
private:
	// Quantity for stacks of items
	int m_stackQuantity;

	// Monetary value in gold
	int m_goldValue;

	// Inventory slot in the player's inventory
	int m_inventorySlot;

	// Icon representing the weapon in the inventory
	sf::Sprite m_iconSprite;
	
public:
	// Getters and Setters
	// Getters
	int getStackQuantity();
	int getGoldValue();
	int getInventorySlot();

	// Setters
	void setStackQuantity(int stackQuantity);
	void setGoldValue(int goldValue);
	void setInventorySlot(int inventorySlot);
};