#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Engine {
private:
	// Pointer to the gameWindow
	sf::RenderWindow *gameWindow;

	// An array of game objects to render (maybe a static array is better)
	std::vector<GameObject> *gameObjects;

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