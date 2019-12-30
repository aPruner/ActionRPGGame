#pragma once
#include "GuiWidget.h"

class DisplayGuiWidget : virtual public GuiWidget {
private:
	// Sprite to be displayed
	sf::Sprite m_displaySprite;

	// Scaling factor (by default, set this to 1)
	int m_displaySpriteScalingFactor;

	// TODO: Figure out what else goes here

public:

	void update() const override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
