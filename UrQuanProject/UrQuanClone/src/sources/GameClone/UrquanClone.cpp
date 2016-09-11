/*
 * UrquanClone.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameClone/UrquanClone.h"

#include "SFML/System/Clock.hpp"
#include <iostream>
#include <unistd.h>

#define MAX_FRAME_UPDATE_INTERVAL 0.25
#define DELTA_TIME 1.f / 60.f

namespace GameClone
{

UrquanClone::UrquanClone() :
		_running(false)
{
}

UrquanClone::~UrquanClone()
{
}

bool UrquanClone::init()
{
	if (!_gameController.init())
	{
		std::cout << "Game Controller failed to initialize properly" << std::endl;
		return false;
	}

	return true;
}

void UrquanClone::execute()
{
	sf::Time elapsedTime = sf::Time::Zero;
	sf::Time accumulator = sf::Time::Zero;

	_clock.restart();

	_running = true;
	while (_running)
	{
		if (!run(elapsedTime, accumulator))
			return;

		elapsedTime = _clock.getElapsedTime();
		_clock.restart();
	}
}

bool UrquanClone::run(const sf::Time& elapsedTime, sf::Time& accumulator)
{
	const sf::Time frameTime =
			elapsedTime > sf::seconds(MAX_FRAME_UPDATE_INTERVAL) ?
					sf::seconds(MAX_FRAME_UPDATE_INTERVAL) : elapsedTime;

	accumulator += frameTime;

	while (accumulator.asSeconds() >= DELTA_TIME)
	{
		if (!update(sf::seconds(DELTA_TIME)))
			return false;

		accumulator -= sf::seconds(DELTA_TIME);
	}

	if (!render())
		return false;

	return true;
}

void UrquanClone::deinit()
{
	std::cout << "Game shutdown!" << std::endl;
}

bool UrquanClone::update(const sf::Time& deltaTime)
{
	if (!_gameController.update(deltaTime))
		return false;

	return true;
}

bool UrquanClone::render()
{
	return true;
}

} /* namespace GameClone */

