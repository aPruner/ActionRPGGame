#include "Game.h"

Game::Game(TextureMap *textureMap, Player *player, sf::Vector2f screenResolution)
{
	m_screenResolution = screenResolution;
	m_player = player;
	m_textureMap = textureMap;
	m_gameObjects = new std::vector<GameObject *>();
	addGameObject(player);
	m_gameView = sf::View(sf::FloatRect(0, 0, screenResolution.x, screenResolution.y));
	m_gameView.setCenter(player->getCenter());
}

Game::~Game()
{
	delete m_gameObjects;
}

Player *Game::getPlayer()
{
	return m_player;
}

sf::View Game::getView()
{
	return m_gameView;
}

std::vector<GameObject *> *Game::getGameObjects()
{
	return m_gameObjects;
}

void Game::addGameObject(GameObject *gameObject)
{
	m_gameObjects->push_back(gameObject);
}