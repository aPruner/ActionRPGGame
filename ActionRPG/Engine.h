#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "TextureMap.h"

class Engine
{
private:
	// SFML Game Window
	sf::RenderWindow *m_gameWindow;

	// TextureMap instance
	TextureMap *m_textureMap;

	// Game instance
	Game *m_game;

	// Player instance
	Player *m_player;

	// Clock instance
	sf::Clock clock;

	// Screen resolution
	sf::Vector2f m_screenResolution;

	// Handle game input
	void input();
	// Update game state
	void update(std::vector<GameObject *> *gameObjects, sf::Clock *clock);
	// Draw the screen
	void draw(std::vector<GameObject *> *gameObjects);

public:
	// Engine constructor, creates the gameWindow
	Engine();
	// Run the game loop
	void run();
};