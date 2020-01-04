#include "TextGuiWidget.h"

TextGuiWidget::TextGuiWidget(std::string string)
{
	m_text = sf::Text();
	m_text.setString(string);
	// NOTE: a TextGuiWidget will never have any children (it will always be a leaf)
	// so this vector will always be empty
	m_childWidgets = new std::vector<GuiWidget>();
}

TextGuiWidget::~TextGuiWidget()
{
}

void TextGuiWidget::update() const
{

}

void TextGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_text, states);
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