#include "DisplayGuiWidget.h"

DisplayGuiWidget::DisplayGuiWidget(sf::Vector2f position, sf::Vector2f parentPosition, float height, float width)
{
	m_guiWidgetConstants = new GuiWidgetConstants();

	m_isVisible = false;
	m_position = position;
	m_parentPosition = parentPosition;
	m_height = height;
	m_width = width;

	// Initialize debug rect
	m_drawDebugRects = true;
	m_debugRectOutline = sf::RectangleShape(sf::Vector2f(width, height));
	m_debugRectOutline.setFillColor(m_guiWidgetConstants->c_defaultDisplayWidgetDebugRectColor);

	// Set the absolute position of the widget
	sf::Vector2f absolutePosition = sf::Vector2f(parentPosition.x + position.x, parentPosition.y + position.y);
	m_debugRectOutline.setPosition(absolutePosition);

	// Create vector of child widgets
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
	if (m_isVisible)
	{
		if (m_drawDebugRects)
		{
			target.draw(m_debugRectOutline, states);
		}

		// TODO: Uncomment when sprites in display widgets are implemented
		// target.draw(m_displaySprite, states);

		// Recursively draw child widgets
		for (auto it = m_childWidgets->begin(); it != m_childWidgets->end(); it++)
		{
			GuiWidget* guiWidget = *it;
			if (guiWidget->getIsVisible())
			{
				guiWidget->draw(target, states);
			}
		}
	}
}