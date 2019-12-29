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

	// The hud view for static hud elements
	sf::View m_hudView;

	// The view for gui elements (such as PlayerSummaryGui, InventoryGui)
	sf::View m_guiView;

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

	void centerGameViewOnPlayer();
	void addGameObject(GameObject *gameObject);

	// Getters and Setters
	// Getters
	sf::View getGameView();
	sf::View getHudView();
	sf::View getDebugView();
	Player *getPlayer();
	Room *getRoom();
	std::vector<GameObject*> *getGameObjects();
};