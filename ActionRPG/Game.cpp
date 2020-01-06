#include "Game.h"

Game::Game(TextureMap *textureMap, sf::Vector2f screenResolution)
{
	m_screenResolution = screenResolution;
	m_textureMap = textureMap;
	m_gameObjects = new std::vector<GameObject *>();
	m_room = new Room(textureMap);
	m_room->createRoom();
	m_player = new Player(m_textureMap, m_room);
	addGameObject(m_player);
	m_gameView = sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y));
	m_gameView.setCenter(m_player->getOrigin());

	// TODO: figure out what else to do with these views (my guess is not much)
	m_hudView = sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y));
	m_guiView = sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y));
	m_debugView = sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y));
}

Game::~Game()
{
	delete m_gameObjects;
}

Player *Game::getPlayer()
{
	return m_player;
}

Room *Game::getRoom()
{
	return m_room;
}

sf::View Game::getGameView()
{
	return m_gameView;
}

sf::View Game::getHudView()
{
	return m_hudView;
}

sf::View Game::getGuiView()
{
	return m_guiView;
}

sf::View Game::getDebugView()
{
	return m_debugView;
}

std::vector<GameObject *> *Game::getGameObjects()
{
	return m_gameObjects;
}

void Game::addGameObject(GameObject *gameObject)
{
	m_gameObjects->push_back(gameObject);
}

void Game::centerGameViewOnPlayer()
{
	m_gameView.setCenter(m_player->getOrigin());
}