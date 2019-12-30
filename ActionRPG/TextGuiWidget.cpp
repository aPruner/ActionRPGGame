#include "TextGuiWidget.h"

TextGuiWidget::TextGuiWidget(std::string string)
{
	m_text = sf::Text();
	m_text.setString(string);
}

TextGuiWidget::~TextGuiWidget()
{
}

void TextGuiWidget::update() const
{

}

void TextGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// TODO: figure out what to draw
	// target.draw(m_sprite, states);
}

// Getters and Setters

// Getters
sf::Text TextGuiWidget::getText()
{
	return m_text;
}

// Setters
void TextGuiWidget::setText(sf::Text text)
{
	m_text = text;
}