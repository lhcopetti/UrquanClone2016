/*
 * UrquanClone.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_URQUANCLONE_H_
#define INCLUDES_URQUANCLONE_H_

#include "SFML/System/Clock.hpp"

#include "GameClone/GameController.h"

namespace GameClone
{

class UrquanClone
{
public:
	UrquanClone();
	virtual ~UrquanClone();

	bool init();
	void deinit();

	void execute();

	bool update(const sf::Time& deltaTime);
	bool render();

private:
	bool run(const sf::Time& elapsedTime, sf::Time& accumulator);
	bool _running;

	sf::Clock _clock;
	GameClone::GameController _gameController;
};

} /* namespace GameClone */

#endif /* INCLUDES_URQUANCLONE_H_ */
