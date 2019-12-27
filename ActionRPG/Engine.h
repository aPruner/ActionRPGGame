#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "TextureMap.h"
#include "EngineConstants.h"

class Engine
{
private:
	// Engine Constants object
	EngineConstants *m_engineConstants;

	// SFML Game Window
	sf::RenderWindow *m_gameWindow;

	// TextureMap instance
	TextureMap *m_textureMap;

	// Game instance
	Game *m_game;

	// Clock instance
	sf::Clock clock;

	// Screen resolution
	sf::Vector2f m_screenResolution;

	// FPS counter text element
	sf::Text m_fpsCounter;

	// FPS counter font
	sf::Font m_fpsCounterFont;

	// Player debug text
	sf::Text m_playerDebugText;

	// Player debug text font
	sf::Font m_playerDebugTextFont;

	// Current FPS value
	float m_fps;

	// Initialize the fps counter
	void initFpsCounter();

	// Initialize the player debug text
	void initPlayerDebugText();

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