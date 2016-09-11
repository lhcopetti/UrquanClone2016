/*
 * GameState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_GAMESTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_GAMESTATE_H_

#include "SFML/System/Time.hpp"

namespace GameState
{

class GameState
{
public:
	GameState();
	virtual ~GameState();

	virtual void update(const sf::Time& deltaTime) = 0;
	virtual void draw() = 0;
};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_GAMESTATE_H_ */
