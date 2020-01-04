#include "WindowGuiWidget.h"

WindowGuiWidget::WindowGuiWidget(sf::Vector2f position)
{
	m_childWidgets = new std::vector<GuiWidget>();
}

WindowGuiWidget::~WindowGuiWidget()
{

}

void WindowGuiWidget::addChildTextWidget(TextGuiWidget newChildTextWidget)
{

}

void WindowGuiWidget::addChildDisplayWidget(DisplayGuiWidget newChildDisplayWidget)
{

}

void WindowGuiWidget::update() const
{

}

void WindowGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// TODO: figure out what to draw
	// target.draw(m_sprite, states);
}