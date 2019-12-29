#include "Gui.h"

// Recurse through widget tree to set isVisible to true for all widgets
void Gui::open()
{
	m_isVisible = true;
	for (auto it = m_widgets->begin(); it != m_widgets->end(); it++)
	{
		it->setIsVisible(true);
	}
}

// Recurse through widget tree to set isVisible to false for all widgets
void Gui::close()
{
	m_isVisible = false;
	for (auto it = m_widgets->begin(); it != m_widgets->end(); it++)
	{
		it->setIsVisible(false);
	}
}