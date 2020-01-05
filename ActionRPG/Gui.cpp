#include "Gui.h"

// Recurse through widget tree to set isVisible to true for all widgets
void Gui::open()
{
	m_isVisible = true;
	m_rootWidget->setIsVisible(true);
}

// Recurse through widget tree to set isVisible to false for all widgets
void Gui::close()
{
	m_isVisible = false;
	m_rootWidget->setIsVisible(false);
}

// Getters and Setters
// Getters
GuiWidget* Gui::getRootWidget()
{
	return m_rootWidget;
}

bool Gui::getIsVisible()
{
	return m_isVisible;
}

// Setters
void Gui::setRootWidget(GuiWidget* newRootWidget)
{
	m_rootWidget = newRootWidget;
}