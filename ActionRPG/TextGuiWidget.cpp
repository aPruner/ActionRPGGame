#include "TextGuiWidget.h"

TextGuiWidget::TextGuiWidget(sf::Vector2f position, sf::Vector2f parentPosition, std::string string, std::string fontFileName)
{
	m_guiWidgetConstants = new GuiWidgetConstants();

	m_font = sf::Font();
	m_font.loadFromFile(fontFileName);

	m_text = sf::Text();
	m_text.setString(string);
	m_text.setFont(m_font);
	m_text.setFillColor(m_guiWidgetConstants->c_defaultTextWidgetFillColor);
	m_text.setCharacterSize(m_guiWidgetConstants->c_defaultTextWidgetFontSize);

	// Set the absolute position of the text
	sf::Vector2f absolutePosition = sf::Vector2f(parentPosition.x + position.x, parentPosition.y + position.y);
	m_text.setPosition(absolutePosition);

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