#include "TextGuiWidget.h"

void TextGuiWidget::update() const
{

}

void TextGuiWidget::draw() const
{

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