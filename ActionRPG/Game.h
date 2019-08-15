#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "TextureMap.h"

class Game
{
private:
	// The game camera view
	sf::View m_gameView;

	// Array of all GameObjects that exist in the Game
	// TODO: Maybe a static array is better (more performant?)
	std::vector<GameObject *> *m_gameObjects;

	// Player instance
	Player *m_player;

	// Pointer to the TextureMap
	TextureMap *m_textureMap;

	// Screen resolution, passed down from the engine
	sf::Vector2f m_screenResolution;

public:
	Game(TextureMap *textureMap, Player *player, sf::Vector2f screenResolution);
	~Game();

	Player *getPlayer();

	std::vector<GameObject *> *getGameObjects();
	void addGameObject(GameObject *gameObject);
};