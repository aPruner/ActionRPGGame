#include "Gui.h"

// Recurse through widget tree to set isVisible to true for all widgets
void Gui::open()
{
	m_isVisible = true;
	// TODO: write this
}

// Recurse through widget tree to set isVisible to false for all widgets
void Gui::close()
{
	m_isVisible = false;
	// TODO: write this
}

// Getters and Setters
// Getters
GuiWidget* Gui::getRootWidget()
{
	return m_rootWidget;
}

// Setters
void Gui::setRootWidget(GuiWidget* newRootWidget)
{
	m_rootWidget = newRootWidget;
}