#pragma once
#include "GuiWidget.h"

// Gui Widget for displaying text within a Gui - to be used within a display widget
class TextGuiWidget : virtual public GuiWidget {
private:
	// Raw string (what the text widget actually says)
	std::string m_string;

	// SFML text representation
	sf::Text m_text;

	// TODO: Figure out what else goes here

public:
	void draw() const override;
	void update() const override;

	// Getters and Setters
	// Getters
	sf::Text getText();

	// Setters
	void setText(sf::Text text);
};
