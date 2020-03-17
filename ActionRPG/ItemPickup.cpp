#include "ItemPickup.h"

ItemPickup::ItemPickup(Item *item)
{
	m_item = item;

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

}