#include "ItemPickup.h"

ItemPickup::ItemPickup(Item *item)
{
	m_item = item;
	m_sprite = item->getPickupSprite();

	// TODO: calculate zPosition
	m_zPosition = 0;
}

ItemPickup::~ItemPickup()
{
}

// Override for GameObject::update
void ItemPickup::update(float timeElapsed)
{

}

// Override for GameObject::draw
void ItemPickup::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}

// Getters and Setters
// Getters
Item* ItemPickup::getItem()
{
	return m_item;
}

// Setters
void ItemPickup::setItem(Item* item)
{
	m_item = item;
}