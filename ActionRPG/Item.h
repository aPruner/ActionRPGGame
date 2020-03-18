#pragma once
#include <SFML/Graphics.hpp>

// Abstract class from which to derive equipable, consumable, and other game items
class Item {
protected:
	// Item name
	std::string m_name;

	// Stack-relevant data
	// Whether or not the item is stackable
	bool m_isStackable;
	// How much of the item there is in this stack
	int m_stackQuantity;
	// Maximum stackQuantity value for this item type
	int m_maxStackQuantity;
	
	// Monetary value in gold
	int m_goldValue;

	// Inventory slot in the player's inventory
	int m_inventorySlot;

	// Icon representing the item in the inventory
	sf::Sprite m_iconSprite;

	// Sprite representing the item pickup (as it exists in the game world)
	sf::Sprite m_pickupSprite;

	// TODO: Add more stuff here as necessary
	
public:
	// Getters and Setters
	// Getters
	std::string const& getName();
	bool getIsStackable();
	int getStackQuantity();
	int getMaxStackQuantity();
	int getGoldValue();
	int getInventorySlot();
	sf::Sprite getPickupSprite();

	// Setters
	void setName(std::string name);
	void setIsStackable(bool isStackable);
	void setStackQuantity(int stackQuantity);
	void setMaxStackQuantity(int maxStackQuantity);
	void setGoldValue(int goldValue);
	void setInventorySlot(int inventorySlot);
	void setPickupSprite(sf::Sprite pickupSprite);
};