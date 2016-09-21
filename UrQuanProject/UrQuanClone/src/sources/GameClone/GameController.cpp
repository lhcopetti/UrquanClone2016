/*
 * GameController.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <iostream>

#include "GameClone/GameController.h"
#include "SFML/System/Time.hpp"

#include "GameMachine/GameState/MainMenuState.h"

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

	if (!_defaultFont.loadFromFile("ARIAL.TTF"))
	{
		std::cout << "Failed to load font Arial.ttf" << std::endl;
		return false;
	}

	if (!_stateController.init(new GameState::MainMenuState(_defaultFont)))
		return false;


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

	_stateController.update(elapsedTime);

	return true;
}

bool GameController::draw()
{
	_window.clear(sf::Color::Black);
	_stateController.draw(_window);
	_window.display();
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
