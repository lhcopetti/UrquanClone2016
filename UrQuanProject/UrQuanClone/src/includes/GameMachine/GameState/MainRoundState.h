/*
 * MainRoundState.h
 *
 *  Created on: 25 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_

#include <GameMachine/GameState/GameState.h>

#include <GameMachine/GameObjects/Ship/Ship.h>

namespace GameState
{

class MainRoundState : public GameState, public Inputs::InputHandler
{
public:
	MainRoundState(GameMachine::GameStateController& controller);
	virtual ~MainRoundState();

	virtual void onEnter();
	virtual void onExit();

	virtual void doUpdate(const sf::Time& deltaTime);
	virtual void doBeforeDraw(sf::RenderWindow& window) const;
	virtual void doDraw(sf::RenderWindow& window);

	sf::Text getDefaultSfText(const std::string& text);

	void transition(GameObjects::ShipType winner, GameObjects::ShipType looser);

	virtual void handleInput(int data);

private:
	GameObjects::GameObject* _shipPlayerOne;
	GameObjects::GameObject* _shipPlayerTwo;

	GameObjects::ShipType _shipTypeOne;
	GameObjects::ShipType _shipTypeTwo;
};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_ */
