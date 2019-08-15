#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Player.h"

// Engine constructor
Engine::Engine()
{
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;
	m_gameWindow = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "Action RPG");

	TextureMap *textureMap = new TextureMap();
	Player *player = new Player(textureMap);
	m_game = new Game(textureMap, player);

	// TODO: Load all the sprites and textures (into respective map data structures) before running the game loop
	// not sure where the code to do this should reside
}

// Draw the screen
void Engine::draw()
{
	m_gameWindow->clear();

	std::vector<GameObject *> *gameObjects = m_game->getGameObjects();

	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		m_gameWindow->draw(**it);
	}
	m_gameWindow->display();
}

// TODO: update the game state
void Engine::update()
{
	return;
}

// Handle input
void Engine::input()
{
	sf::Event event;
	while (m_gameWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_gameWindow->close();
		}
	}
}

// Run the game loop
void Engine::run()
{
	while (m_gameWindow->isOpen())
	{
		input();
		update();
		draw();
	}
}