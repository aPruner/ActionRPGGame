#pragma once
#include "Gui.h"
#include "Player.h"

class PlayerGui : public Gui {
private:
	Player *m_player;
public:
	void addPlayerAttributeWidgets();
};
