/*
 * GameController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameClone/GameController.h"
#include "SFML/System/Time.hpp"

namespace GameClone
{

GameController::GameController()
{

}

GameController::~GameController()
{
}

bool GameController::init()
{
	_window.create(sf::VideoMode(1366, 768), "Urquan Clone");
	_window.clear(sf::Color::Blue);

//	if (!_stateController.init())

	return true;
}

void GameController::deinit()
{
	_window.close();
}

bool GameController::update(const sf::Time& elapsedTime)
{
	if (!_window.isOpen())
		return false;

	if (!pollWindowEvents())
		return false;

	return true;
}

bool GameController::draw()
{
	return true;
}

bool GameController::pollWindowEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_window.close();
			return false;
		}
	}

	return true;
}

} /* namespace GameClone */
