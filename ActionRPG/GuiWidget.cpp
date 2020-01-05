#include "GuiWidget.h"
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
		(*it)->setIsVisible(isVisible);
	}
}
