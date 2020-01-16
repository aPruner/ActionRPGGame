#include "Engine.h"

Engine::Engine()
{
	// Initialize constants object
	m_engineConstants = new EngineConstants();

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

	m_guiInstances = new std::vector<Gui *>();

	// Initialize Player Gui
	m_playerSummaryGui = new PlayerSummaryGui(m_game->getPlayer());

	// Add gui instances to vector (for drawing later)
	m_guiInstances->push_back(m_playerSummaryGui);
}

// Initialize the fps counter
void Engine::initFpsCounter()
{
	m_fpsCounterFont.loadFromFile(m_engineConstants->c_defaultFontFilename);
	m_fpsCounter.setString(m_engineConstants->c_fpsCounterInitString);
	m_fpsCounter.setFont(m_fpsCounterFont);
	m_fpsCounter.setCharacterSize(m_engineConstants->c_defaultFontSize);
	m_fpsCounter.setFillColor(m_engineConstants->c_defaultFontColor);
	m_fpsCounter.setPosition(m_engineConstants->c_fpsCounterPosition);
	m_timeSinceLastFpsUpdateSeconds = 0;
}

void Engine::initPlayerDebugText()
{
	m_playerDebugTextPosition = sf::Vector2f(m_screenResolution.x - m_engineConstants->c_playerDebugTextOffsetX, m_screenResolution.y - m_engineConstants->c_playerDebugTextOffsetY);
	m_playerDebugTextFont.loadFromFile(m_engineConstants->c_defaultFontFilename);
	m_playerDebugText.setString(m_engineConstants->c_playerDebugTextInitString);
	m_playerDebugText.setFont(m_playerDebugTextFont);
	m_playerDebugText.setCharacterSize(m_engineConstants->c_defaultFontSize);
	m_playerDebugText.setFillColor(m_engineConstants->c_defaultFontColor);
	m_playerDebugText.setPosition(m_playerDebugTextPosition);
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
		// TODO: Constants for default controls in EngineConstants.h
		if (event.type == sf::Event::KeyPressed)
		{
			// For now, escape quits the game
			if (event.key.code == sf::Keyboard::Escape)
			{
				m_gameWindow->close();
			}

			// Open or close the PlayerSummaryGui
			if (event.key.code == sf::Keyboard::C)
			{
				if (m_playerSummaryGui->getIsVisible())
				{
					m_playerSummaryGui->close();
				}
				else
				{
					m_playerSummaryGui->open();
				}
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

		// Handle Attack (for now the control will be space)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			player->attack();
		}
		else
		{
			player->stopAttack();
		}

	}
}

// Update the game state
void Engine::update(std::vector<GameObject *> *gameObjects, sf::Clock *clock)
{

	sf::Time dt = clock->restart();
	float dtSeconds = dt.asSeconds();
	m_timeSinceLastFpsUpdateSeconds += dtSeconds;
	if (m_timeSinceLastFpsUpdateSeconds > 1) {
		m_fps = 1.f / dtSeconds;
		m_fpsInt = (int)m_fps;
		m_fpsCounter.setString(m_engineConstants->c_fpsCounterInitString + std::to_string(m_fpsInt));
		m_timeSinceLastFpsUpdateSeconds = 0;
	}

	for (auto it = gameObjects->begin(); it != gameObjects->end(); it++)
	{
		(*it)->update(dtSeconds);
	}

	std::stringstream debugSS;
	debugSS << m_engineConstants->c_playerDebugTextInitString << m_game->getPlayer()->getIsFacingLeft() << '\n';
	debugSS << m_engineConstants->c_playerInvertedXDebugString << m_game->getPlayer()->getRunAnimation()->getIsInvertedX() << '\n';
	debugSS << m_engineConstants->c_playerSpriteScaleDebugString << '(' << m_game->getPlayer()->getRunAnimation()->getFrameSprite()->getScale().x << ", " << m_game->getPlayer()->getRunAnimation()->getFrameSprite()->getScale().y << ')';
	m_playerDebugText.setString(debugSS.str());

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
	m_gameWindow->draw(m_game->getRoom()->getRoomVA(), &m_textureMap->getRoomSpriteSheet());
	m_gameWindow->draw(m_game->getRoom()->getRoomWallLayerVA(), &m_textureMap->getRoomSpriteSheet());

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

	// Draw the guis
	m_gameWindow->setView(m_game->getGuiView());
	for (auto it = m_guiInstances->begin(); it != m_guiInstances->end(); it++)
	{
		Gui *guiInstance = *it;
		m_gameWindow->draw(*guiInstance->getRootWidget());
	}

	// Draw the debug text overlays
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