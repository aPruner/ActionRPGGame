#include "Game.h"

Game::Game()
{
	m_gameObjects = new std::vector<GameObject *>();
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