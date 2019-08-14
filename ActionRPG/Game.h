#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
private:
	// The game camera view
	sf::View m_gameView;

	// Array of all GameObjects that exist in the Game
	// TODO: Maybe a static array is better (more performant?)
	std::vector<GameObject *> *m_gameObjects;
public:
	Game();
	~Game();

	std::vector<GameObject *> *getGameObjects();
	void addGameObject(GameObject *gameObject);
};