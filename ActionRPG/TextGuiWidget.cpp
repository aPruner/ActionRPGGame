#include "TextGuiWidget.h"

TextGuiWidget::TextGuiWidget(std::string string)
{
	m_text = sf::Text();
	m_text.setString(string);
	// NOTE: a TextGuiWidget will never have any children (it will always be a leaf)
	// so this vector will always be empty
	m_childWidgets = new std::vector<GuiWidget *>();
}

TextGuiWidget::~TextGuiWidget()
{
}

// Override of GuiWidget::update
void TextGuiWidget::update() const
{

}

// Override of GuiWidget::draw
void TextGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if (m_isVisible)
	{
		target.draw(m_text, states);
		// target.draw(m_debugRectOutline, states);
	}
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