#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include "GameObject.h"
#include "Game.h"
#include "Gui.h"
#include "TextureMap.h"
#include "EngineConstants.h"
#include "PlayerSummaryGui.h"
#include "Player.h"


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

	// PlayerSummaryGui instance
	PlayerSummaryGui *m_playerSummaryGui;

	// TODO: decide if this is necessary, may be easier to just draw each gui one at a time
	// Vector of all gui instances
	std::vector<Gui*>* m_guiInstances;

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
	// Player debug text position - dependent on resolution
	sf::Vector2f m_playerDebugTextPosition;

	// Current FPS value
	float m_fps;
	int m_fpsInt;
	float m_timeSinceLastFpsUpdateSeconds;

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