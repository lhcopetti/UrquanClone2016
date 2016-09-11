/*
 * GameController.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMECHANICS_GAMECONTROLLER_H_
#define INCLUDES_GAMEMECHANICS_GAMECONTROLLER_H_

#include "GameMachine/GameStateController.h"

#include "SFML/Graphics.hpp"

namespace sf
{
	class Time;
}

namespace GameClone
{

class GameController
{
public:
	GameController();
	virtual ~GameController();

	bool init();
	void deinit();

	bool update(const sf::Time& elapsedTime);
	bool draw();

	bool pollWindowEvents();

private:

	GameMachine::GameStateController _stateController;
	sf::RenderWindow _window;
};

} /* namespace GameClone */

#endif /* INCLUDES_GAMEMECHANICS_GAMECONTROLLER_H_ */
