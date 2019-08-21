#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "TextureMap.h"
#include "Room.h"

class Game
{
private:
	// The game camera view
	sf::View m_gameView;

	// The hud view for text and other info
	sf::View m_hudView;

	// The view for debugging info
	sf::View m_debugView;

	// Array of all GameObjects that exist in the Game
	// TODO: Maybe a static array is better (more performant?)
	std::vector<GameObject *> *m_gameObjects;

	// Player instance
	Player *m_player;

	// Pointer to the TextureMap
	TextureMap *m_textureMap;

	// Screen resolution, passed down from the engine
	sf::Vector2f m_screenResolution;

	// Instance of the room
	Room *m_room;

public:
	Game(TextureMap *textureMap, sf::Vector2f screenResolution);
	~Game();

	sf::View getGameView();
	sf::View getHudView();
	sf::View getDebugView();

	void centerGameViewOnPlayer();

	Player *getPlayer();

	Room *getRoom();

	std::vector<GameObject *> *getGameObjects();
	void addGameObject(GameObject *gameObject);
};