/*
 * UrquanClone.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_URQUANCLONE_H_
#define INCLUDES_URQUANCLONE_H_

#include "SFML/System/Clock.hpp"

namespace GameClone
{

class UrquanClone
{
public:
	UrquanClone();
	virtual ~UrquanClone();

	void start();
	void shutdown();

	void update(const sf::Time& deltaTime);
	void render();

private:
	void run(const sf::Time& elapsedTime, sf::Time& accumulator);
	bool _running;

	sf::Clock _clock;
};

} /* namespace GameClone */

#endif /* INCLUDES_URQUANCLONE_H_ */
