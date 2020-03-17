#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Item.h"

// A class that represents an item that can be picked up by a player
class ItemPickup : virtual public GameObject
{
private:
	// Instance of the actual item
	Item *m_item;

	// Z-index position in case items are stacked
	// TODO: design and implement this feature
	int m_zPosition;

	// TODO: add more here if necessary
public:

	ItemPickup(Item *item);
	~ItemPickup();

	// Override for GameObject::update
	void update(float timeElapsed) override;

	// Override for GameObject::draw
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Getters and Setters
	// Getters
	Item *getItem();

	// Setters
	void setItem(Item* item);
};