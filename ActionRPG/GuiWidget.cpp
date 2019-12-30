#include "GuiWidget.h"

// Override of GuiWidget::update
void GuiWidget::update() const
{

}

// Override of GuiWidget::draw
void GuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// TODO: figure out what to draw
	// target.draw(m_sprite, states);
}

// Getters and Setters

// Getters
bool GuiWidget::getIsVisible()
{
	return m_isVisible;
}

// Setters
void GuiWidget::setIsVisible(bool isVisible)
{
	m_isVisible = isVisible;
	for (auto it = m_childWidgets->begin(); it != m_childWidgets->end(); it++)
	{
		it->setIsVisible(isVisible);
	}
}