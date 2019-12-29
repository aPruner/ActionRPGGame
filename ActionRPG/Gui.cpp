#include "Gui.h"

void Gui::open()
{
	m_isVisible = true;
	for (auto it = m_widgets->begin(); it != m_widgets->end(); it++)
	{
		it->setIsVisible(true);
	}
}

void Gui::close()
{
	m_isVisible = false;
	for (auto it = m_widgets->begin(); it != m_widgets->end(); it++)
	{
		it->setIsVisible(false);
	}
}