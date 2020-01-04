#include "DisplayGuiWidget.h"

DisplayGuiWidget::DisplayGuiWidget(sf::Vector2f position)
{
	m_childWidgets = new std::vector<GuiWidget>();
}

DisplayGuiWidget::~DisplayGuiWidget()
{

}

void DisplayGuiWidget::addChildTextWidget(TextGuiWidget newChildTextWidget)
{

}

void DisplayGuiWidget::addChildDisplayWidget(DisplayGuiWidget newChildDisplayWidget)
{

}

void DisplayGuiWidget::update() const
{

}

void DisplayGuiWidget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}