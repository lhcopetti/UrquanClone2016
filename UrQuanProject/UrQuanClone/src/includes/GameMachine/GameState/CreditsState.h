/*
 * CreditsState.h
 *
 *  Created on: 26 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_CREDITSSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_CREDITSSTATE_H_

#include <GameMachine/GameState/GameState.h>
#include <SFML/System/Time.hpp>

namespace GameState
{

class CreditsState: public GameState::GameState, public Inputs::InputHandler
{
public:
	CreditsState(GameMachine::GameStateController& controller);
	virtual ~CreditsState();

	virtual void onEnter();
	virtual void onExit();

	virtual void handleInput(Inputs::InputAction inputAction);
	virtual void handleInput(int data);

	virtual void doUpdate(const sf::Time& deltaTime);
	virtual void doBeforeDraw(sf::RenderWindow& window) const;

private:
	sf::Time _counter;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_CREDITSSTATE_H_ */
