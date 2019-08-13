#include <SFML/Graphics.hpp>

class Engine {
private:
	// Pointer to the gameWindow
	sf::RenderWindow *gameWindow;

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