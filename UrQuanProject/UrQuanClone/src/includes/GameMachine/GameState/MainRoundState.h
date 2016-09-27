/*
 * MainRoundState.h
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_

#include <GameMachine/GameState/GameState.h>

namespace GameState
{

class MainRoundState : public GameState
{
public:
	MainRoundState(GameMachine::GameStateController& controller);
	virtual ~MainRoundState();

	virtual void onEnter();
	virtual void onExit();

	virtual void doUpdate(const sf::Time& deltaTime);
	virtual void doDraw(sf::RenderWindow& window);
};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_ */
