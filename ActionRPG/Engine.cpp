#include <SFML/Graphics.hpp>
#include "Engine.h"

// Engine constructor
Engine::Engine()
{
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;
	gameWindow = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), "Action RPG");
}

// Draw the screen
void Engine::draw()
{
	gameWindow->clear();
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