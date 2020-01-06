#include "WindowGuiWidget.h"

WindowGuiWidget::WindowGuiWidget(sf::Vector2f position, float height, float width)
{
	m_position = position;
	// WindowGuiWidgets will always be root, so they have a parentPosition of 0, 0 by default
	m_parentPosition = sf::Vector2f(0, 0);
	m_height = height;
	m_width = width;
	// Initialize debug rect
	m_drawDebugRects = true;
	m_debugRectOutline = sf::RectangleShape(sf::Vector2f(width, height));
	m_debugRectOutline.setPosition(position);
	m_debugRectOutline.setFillColor(sf::Color::Yellow);
	m_debugRectOutline.setOutlineColor(sf::Color::White);

	// Create vector of child widgets
	m_childWidgets = new std::vector<GuiWidget *>();
}

WindowGuiWidget::~WindowGuiWidget()
{
}

void WindowGuiWidget::addChildTextWidget(TextGuiWidget *newChildTextWidget)
{
	m_childWidgets->push_back(newChildTextWidget);
}

void WindowGuiWidget::addChildDisplayWidget(DisplayGuiWidget *newChildDisplayWidget)
{
	m_childWidgets->push_back(newChildDisplayWidget);
}

// Override of GuiWidget::update
void WindowGuiWidget::update() const
{
}

// Override of GuiWidget::draw
// Draw's the WindowGuiWidgets debug rect (later on non debug stuff)
// and then recurses through the widget tree, drawing each widget node
void WindowGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if (m_isVisible)
	{
		// Draw this widget
		// target.draw(m_backgroundRect, states);
		if (m_drawDebugRects)
		{
			target.draw(m_debugRectOutline, states);
		}
		
		// Recursively draw child widgets
		for (auto it = m_childWidgets->begin(); it != m_childWidgets->end(); it++)
		{
			GuiWidget *guiWidget = *it;
			if (guiWidget->getIsVisible())
			{
				guiWidget->draw(target, states);
			}
		}
	}
}