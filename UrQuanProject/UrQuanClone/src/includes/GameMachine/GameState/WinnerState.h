/*
 * WinnerState.h
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMESTATE_WINNERSTATE_H_
#define SOURCES_GAMEMACHINE_GAMESTATE_WINNERSTATE_H_

#include <GameMachine/GameState/GameState.h>

namespace GameState
{

class WinnerState: public GameState::GameState, public Inputs::InputHandler
{
public:
	WinnerState(GameMachine::GameStateController& controller);
	virtual ~WinnerState();

	virtual void onEnter();
	virtual void onExit();

	virtual void handleInput(int data);

	virtual void doUpdate(const sf::Time& deltaTime);
	virtual void doBeforeDraw(sf::RenderWindow& window) const;

private:

};

} /* namespace Armory */

#endif /* SOURCES_GAMEMACHINE_GAMESTATE_WINNERSTATE_H_ */
