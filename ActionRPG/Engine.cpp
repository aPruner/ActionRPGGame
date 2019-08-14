#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Player.h"

// Engine constructor
Engine::Engine()
{
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;
	gameWindow = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "Action RPG");

	// TODO: Relevant when there are multiple game objects to draw
	// gameObjects = new std::vector<GameObject>();

	// TODO: add the player to the game and draw him/her
	Player *player = new Player();

}

// Draw the screen
void Engine::draw()
{
	gameWindow->clear();
	// TODO: Draw the player
	// gameWindow->draw();
	gameWindow->display();
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
	while (gameWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			gameWindow->close();
		}
	}
}

// Run the game loop
void Engine::run()
{
	while (gameWindow->isOpen())
	{
		input();
		update();
		draw();
	}
}