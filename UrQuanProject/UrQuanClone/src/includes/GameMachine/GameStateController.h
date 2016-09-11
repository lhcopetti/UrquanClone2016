/*
 * GameStateController.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_
#define INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_

#include "GameMachine/GameState/GameState.h"

namespace sf
{
class Time;
}

namespace GameMachine
{

class GameStateController
{
public:
	GameStateController();
	virtual ~GameStateController();

	bool init(GameState::GameState* initialState);
	void deinit();

	void update(const sf::Time& time);
	void draw();

private:

};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATECONTROLLER_H_ */
