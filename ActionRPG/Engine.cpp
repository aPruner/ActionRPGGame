#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Engine.h"
#include "Player.h"

Engine::Engine()
{
	// Create the game window
	sf::VideoMode screenResolutionVM = sf::VideoMode::getDesktopMode();
	m_screenResolution = sf::Vector2f((float) screenResolutionVM.width, (float) screenResolutionVM.height);
	m_gameWindow = new sf::RenderWindow(screenResolutionVM, "Action RPG", sf::Style::Fullscreen);

	// Initialize the fps counter
	initFpsCounter();

	// Initializie the player debug text
	initPlayerDebugText();

	// Initialize the game
	m_textureMap = new TextureMap();
	m_game = new Game(m_textureMap, m_screenResolution);
}

// Initialize the fps counter
void Engine::initFpsCounter()
{
	m_fpsCounterFont.loadFromFile(c_defaultFontFilename);
	m_fpsCounter.setString(c_fpsCounterInitString);
	m_fpsCounter.setFont(m_fpsCounterFont);
	m_fpsCounter.setCharacterSize(c_defaultFontSize);
	m_fpsCounter.setFillColor(c_defaultFontColor);
	m_fpsCounter.setPosition(c_fpsCounterPosition);
}

void Engine::initPlayerDebugText()
{
	m_playerDebugTextFont.loadFromFile(c_defaultFontFilename);
	m_playerDebugText.setString(c_playerDebugTextInitString);
	m_playerDebugText.setFont(m_playerDebugTextFont);
	m_playerDebugText.setCharacterSize(c_defaultFontSize);
	m_playerDebugText.setFillColor(c_defaultFontColor);
	m_playerDebugText.setPosition(c_playerDebugTextPosition);
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

		Player *player = m_game->getPlayer();

		// Handle movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player->move(GameObject::Direction::UP);
		}
		else
		{
			player->stopMove(GameObject::Direction::UP);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player->move(GameObject::Direction::DOWN);
		}
		else
		{
			player->stopMove(GameObject::Direction::DOWN);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player->move(GameObject::Direction::LEFT);
		}
		else
		{
			player->stopMove(GameObject::Direction::LEFT);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player->move(GameObject::Direction::RIGHT);
		}
		else
		{
			player->stopMove(GameObject::Direction::RIGHT);
		}

	}
}

// Update the game state
void Engine::update(std::vector<GameObject *> *gameObjects, sf::Clock *clock)
{
	// TODO: Figure out how to center the view on the player

	sf::Time dt = clock->restart();
	float dtSeconds = dt.asSeconds();
	m_fps = 1.f / dtSeconds;
	m_fpsCounter.setString(c_fpsCounterInitString + std::to_string(m_fps));

	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		(*it)->update(dtSeconds);
	}

	// Set the player debug text info after updating all GameObjects
	char playerDebugTextBuffer[50];
	sprintf_s(playerDebugTextBuffer, c_playerDebugTextInitString.c_str(), m_game->getPlayer()->getXPositionInTileMap(), m_game->getPlayer()->getYPositionInTileMap());
	m_playerDebugText.setString(std::string(playerDebugTextBuffer));

	// Update the GameView's center point to be the player
	m_game->centerGameViewOnPlayer();
}

// Draw the screen
void Engine::draw(std::vector<GameObject *> *gameObjects)
{
	// Draw everything in the gameView
	m_gameWindow->clear();
	m_gameWindow->setView(m_game->getGameView());

	// Draw the room
	m_gameWindow->draw(m_game->getRoom()->getRoomVA(), &m_textureMap->getSpriteSheet());

	// Draw debug rects for tiles
	Tile **roomTileMap = m_game->getRoom()->getRoomTileMap();
	int yRoomTileMapSize = m_game->getRoom()->getMaxRoomHeightTiles();
	int xRoomTileMapSize = m_game->getRoom()->getMaxRoomWidthTiles();
	for (int i = 0; i < yRoomTileMapSize; i++)
	{
		for (int j = 0; j < xRoomTileMapSize; j++)
		{
			Tile *tile = roomTileMap[i * yRoomTileMapSize + j];
			if (tile->getDebugStatus())
			{
				m_gameWindow->draw(tile->getDebugRectangleShape());
			}
		}
	}

	// Draw the gameObjects
	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		GameObject *gameObject = *it;
		m_gameWindow->draw(*gameObject);
		if (gameObject->getDebugStatus())
		{
			m_gameWindow->draw(gameObject->getDebugRectOutline());
			m_gameWindow->draw(gameObject->getDebugRectOrigin());
		}
	}

	// Draw the text overlays
	m_gameWindow->setView(m_game->getDebugView());
	m_gameWindow->draw(m_playerDebugText);
	m_gameWindow->draw(m_fpsCounter);

	// Display the new frame
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