#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Player.h"

Engine::Engine()
{
	sf::VideoMode screenResolutionVM = sf::VideoMode::getDesktopMode();
	m_screenResolution = sf::Vector2f((float) screenResolutionVM.width, (float) screenResolutionVM.height);
	m_gameWindow = new sf::RenderWindow(screenResolutionVM, "Action RPG", sf::Style::Fullscreen);

	m_textureMap = new TextureMap();
	m_player = new Player(m_textureMap);
	m_game = new Game(m_textureMap, m_player, m_screenResolution);

	// TODO: Maybe it'd be better to load all the sprites and textures (into respective map data structures)
	// before running the game loop, not sure where the code to do this should reside
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
		}

		// Handle movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_player->move(GameObject::Direction::UP);
		}
		else
		{
			m_player->stopMove(GameObject::Direction::UP);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_player->move(GameObject::Direction::DOWN);
		}
		else
		{
			m_player->stopMove(GameObject::Direction::DOWN);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_player->move(GameObject::Direction::LEFT);
		}
		else
		{
			m_player->stopMove(GameObject::Direction::LEFT);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_player->move(GameObject::Direction::RIGHT);
		}
		else
		{
			m_player->stopMove(GameObject::Direction::RIGHT);
		}

	}
}

// Update the game state
void Engine::update(std::vector<GameObject *> *gameObjects, sf::Clock *clock)
{
	sf::Time dt = clock->restart();
	float dtSeconds = dt.asSeconds();
	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		(*it)->update(dtSeconds);
	}
}

// Draw the screen
void Engine::draw(std::vector<GameObject *> *gameObjects)
{
	// Draw everything in the gameView
	m_gameWindow->clear();
	m_gameWindow->setView(m_game->getView());

	// Draw the room
	m_gameWindow->draw(m_game->getRoom()->getRoomVA(), &m_textureMap->getSpriteSheet());

	// Draw the gameObjects
	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		m_gameWindow->draw(**it);
	}
	m_gameWindow->display();
}

// Run the game loop
void Engine::run()
{
	sf::Clock *clock = new sf::Clock();
	while (m_gameWindow->isOpen())
	{
		std::vector<GameObject *> *gameObjects = m_game->getGameObjects();
		input();
		update(gameObjects, clock);
		draw(gameObjects);
	}
}