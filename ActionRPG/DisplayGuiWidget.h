#pragma once
#include "GuiWidget.h"
#include "TextGuiWidget.h"

class DisplayGuiWidget : virtual public GuiWidget {
private:
	// Sprite to be displayed
	sf::Sprite m_displaySprite;

	// Scaling factor (by default, set this to 1)
	int m_displaySpriteScalingFactor;

	// TODO: Figure out what else goes here
public:

	DisplayGuiWidget(sf::Vector2f position);
	~DisplayGuiWidget();

	// TODO: make a new sub type of GuiWidget in the class hierarchy tree so that this isn't duplicate code in WindowGuiWidget
	void addChildTextWidget(TextGuiWidget newChildTextWidget);
	void addChildDisplayWidget(DisplayGuiWidget newChildDisplayWidget);

	void update() const override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
