#include "WindowGuiWidget.h"

WindowGuiWidget::WindowGuiWidget(sf::Vector2f position)
{
	m_childWidgets = new std::vector<GuiWidget *>();
}

WindowGuiWidget::~WindowGuiWidget()
{

}

void WindowGuiWidget::addChildTextWidget(TextGuiWidget newChildTextWidget)
{
	m_childWidgets->push_back(&newChildTextWidget);
}

void WindowGuiWidget::addChildDisplayWidget(DisplayGuiWidget newChildDisplayWidget)
{
	m_childWidgets->push_back(&newChildDisplayWidget);
}

// Override of GuiWidget::update
void WindowGuiWidget::update() const
{

}

// Override of GuiWidget::draw
void WindowGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// target.draw(m_backgroundRect, states);

	target.draw(m_debugRectOutline, states);
}