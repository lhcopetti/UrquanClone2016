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

void UrquanClone::start()
{
	_running = true;

	sf::Time elapsedTime = sf::Time::Zero;
	sf::Time accumulator = sf::Time::Zero;

	_clock.restart();

	while (_running)
	{
		run(elapsedTime, accumulator);
		elapsedTime = _clock.getElapsedTime();
		_clock.restart();
	}
}

void UrquanClone::run(const sf::Time& elapsedTime, sf::Time& accumulator)
{
	const sf::Time frameTime =
			elapsedTime > sf::seconds(MAX_FRAME_UPDATE_INTERVAL) ?
					sf::seconds(MAX_FRAME_UPDATE_INTERVAL) : elapsedTime;

	accumulator += frameTime;

	while (accumulator.asSeconds() >= DELTA_TIME)
	{
		update(sf::seconds(DELTA_TIME));
		accumulator -= sf::seconds(DELTA_TIME);
	}

	render();

	std::cout << "Elapsed time: " << elapsedTime.asSeconds() << " seconds"
			<< std::endl;
	sleep(0.15);
}

void UrquanClone::shutdown()
{
	std::cout << "Game shutdown!" << std::endl;
}

void UrquanClone::update(const sf::Time& deltaTime)
{
	std::cout << "Calling update!  - " << deltaTime.asMilliseconds() << std::endl;
}

void UrquanClone::render()
{
	std::cout << "Calling Render!  - " << std::endl;
}

} /* namespace GameClone */
