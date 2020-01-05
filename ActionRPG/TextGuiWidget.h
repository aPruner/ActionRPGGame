#pragma once
#include "GuiWidget.h"

// Gui Widget for displaying text within a Gui - to be used within a display widget
class TextGuiWidget : virtual public GuiWidget {
private:
	// Raw string (what the text widget actually says)
	std::string m_string;

	// SFML text representation
	sf::Text m_text;

	// Font for the TextGuiWidget
	sf::Font m_font;

	// TODO: Figure out what else goes here

public:
	TextGuiWidget(sf::Vector2f position, sf::Vector2f parentPosition, std::string string, std::string fontFileName);
	~TextGuiWidget();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update() const override;

	// Getters and Setters
	// Getters
	sf::Text getText();

	// Setters
	void setText(sf::Text text);
};
