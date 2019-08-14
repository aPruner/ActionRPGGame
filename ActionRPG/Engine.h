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

	// Handle game input
	void input();
	// Update game state
	void update();
	// Draw the screen
	void draw();

public:
	// Engine constructor, creates the gameWindow
	Engine();
	// Run the game loop
	void run();
};