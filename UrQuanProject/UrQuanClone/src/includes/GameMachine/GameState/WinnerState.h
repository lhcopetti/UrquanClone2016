/*
 * WinnerState.h
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMESTATE_WINNERSTATE_H_
#define SOURCES_GAMEMACHINE_GAMESTATE_WINNERSTATE_H_

#include <GameMachine/GameState/GameState.h>

#include <GameMachine/GameObjects/Ship/Ship.h>
#include <SFML/Graphics/Text.hpp>

namespace GameState
{

class WinnerState: public GameState::GameState, public Inputs::InputHandler
{
public:
	WinnerState(GameMachine::GameStateController& controller, GameObjects::ShipType winner, GameObjects::ShipType looser);
	virtual ~WinnerState();

	virtual void onEnter();
	virtual void onExit();

	virtual void handleInput(int data);

	virtual void doUpdate(const sf::Time& deltaTime);
	virtual void doBeforeDraw(sf::RenderWindow& window) const;

private:
	GameObjects::ShipType _winner;
	GameObjects::ShipType _looser;

	sf::Text _textWinner;
	sf::Text _textLooser;
};

} /* namespace Armory */

#endif /* SOURCES_GAMEMACHINE_GAMESTATE_WINNERSTATE_H_ */
