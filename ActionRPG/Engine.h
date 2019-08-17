#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Game.h"
#include "TextureMap.h"

class Engine
{
private:
	const std::string c_fpsCounterFontFilename = "fonts/MiddleEarth.ttf";
	const std::string c_fpsCounterInitString = "FPS: ";
	// TODO: Change the position of the fpsCounter to be related to resolution
	const sf::Vector2f c_fpsCounterPosition = sf::Vector2f(-950, -550);
	const sf::Color c_fpsCounterTextColor = sf::Color::White;
	// TODO: Change the font size of the fpsCounter to be related to resolution
	const static int c_fpsCounterFontSize = 50;

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

	// FPS counter text element
	sf::Text m_fpsCounter;

	// FPS counter font
	sf::Font m_fpsCounterFont;

	// Current FPS value
	float m_fps;

	// Initialize the fps counter
	void initFpsCounter();

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