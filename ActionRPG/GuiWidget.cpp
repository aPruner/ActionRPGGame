#include "GuiWidget.h"

// Override of GuiWidget::update
void GuiWidget::update() const
{

}

// Override of GuiWidget::draw
void GuiWidget::draw() const
{

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
}