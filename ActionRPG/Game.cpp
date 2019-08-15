#include "Game.h"

Game::Game(TextureMap *textureMap, Player *player)
{
	m_player = player;
	m_textureMap = textureMap;
	m_gameObjects = new std::vector<GameObject *>();
	m_gameObjects->push_back(m_player);
}

Game::~Game()
{
	delete m_gameObjects;
}

std::vector<GameObject *> *Game::getGameObjects()
{
	return m_gameObjects;
}

void Game::addGameObject(GameObject *gameObject)
{
	m_gameObjects->push_back(gameObject);
}