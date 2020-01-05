#include "DisplayGuiWidget.h"

DisplayGuiWidget::DisplayGuiWidget(sf::Vector2f position, sf::Vector2f parentPosition, float height, float width)
{
	m_position = position;
	m_parentPosition = parentPosition;
	m_height = height;
	m_width = width;
	m_childWidgets = new std::vector<GuiWidget *>();
}

DisplayGuiWidget::~DisplayGuiWidget()
{

}

void DisplayGuiWidget::addChildTextWidget(TextGuiWidget *newChildTextWidget)
{
	m_childWidgets->push_back(newChildTextWidget);
}

void DisplayGuiWidget::addChildDisplayWidget(DisplayGuiWidget *newChildDisplayWidget)
{
	m_childWidgets->push_back(newChildDisplayWidget);
}
// Override of GuiWidget::update
void DisplayGuiWidget::update() const
{

}

// Override of GuiWidget::draw
void DisplayGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// target.draw(m_displaySprite, states);

	if (m_isVisible)
	{
		target.draw(m_debugRectOutline, states);
	}
}