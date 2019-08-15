#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Player.h"

// Engine constructor
Engine::Engine()
{
	sf::VideoMode screenResolutionVM = sf::VideoMode::getDesktopMode();
	m_screenResolution = sf::Vector2f((float) screenResolutionVM.width, (float) screenResolutionVM.height);
	m_gameWindow = new sf::RenderWindow(screenResolutionVM, "Action RPG");

	m_textureMap = new TextureMap();
	m_player = new Player(m_textureMap);
	m_game = new Game(m_textureMap, m_player, m_screenResolution);

	// TODO: Load all the sprites and textures (into respective map data structures) before running the game loop
	// not sure where the code to do this should reside
}

// Handle input
void Engine::input()
{
	sf::Event event;
	while (m_gameWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_gameWindow->close();
		}

		// TODO: Implement a control map to allow for switching controls
		if (event.type == sf::Event::KeyPressed)
		{

			// For now, escape quits the game
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_gameWindow->close();
			}

			// Handle movement
			if (event.key.code == sf::Keyboard::W)
			{
				m_player->move(GameObject::Direction::UP);
			}
			else
			{
				m_player->stopMove(GameObject::Direction::UP);
			}

			if (event.key.code == sf::Keyboard::S)
			{
				m_player->move(GameObject::Direction::DOWN);
			}
			else
			{
				m_player->stopMove(GameObject::Direction::DOWN);
			}

			if (event.key.code == sf::Keyboard::A)
			{
				m_player->move(GameObject::Direction::LEFT);
			}
			else
			{
				m_player->stopMove(GameObject::Direction::LEFT);
			}

			if (event.key.code == sf::Keyboard::D)
			{
				m_player->move(GameObject::Direction::RIGHT);
			}
			else
			{
				m_player->stopMove(GameObject::Direction::RIGHT);
			}
		}

	}
}

// TODO: update the game state
void Engine::update(std::vector<GameObject *> *gameObjects, sf::Clock clock)
{
	sf::Time dt = clock.restart();
	float dtSeconds = dt.asSeconds();
	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		(*it)->update(dtSeconds);
	}
}

// Draw the screen
void Engine::draw(std::vector<GameObject *> *gameObjects)
{
	m_gameWindow->clear();

	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		m_gameWindow->draw(**it);
	}
	m_gameWindow->display();
}

// Run the game loop
void Engine::run()
{
	// Clock for keeping track of timeElapsed
	sf::Clock clock;
	while (m_gameWindow->isOpen())
	{
		std::vector<GameObject *> *gameObjects = m_game->getGameObjects();
		input();
		update(gameObjects, clock);
		draw(gameObjects);
	}
}