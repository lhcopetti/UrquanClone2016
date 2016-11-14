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
	virtual void doBeforeDraw(sf::RenderWindow& window) const;
	virtual void doDraw(sf::RenderWindow& window);

	sf::Text getDefaultSfText(const std::string& text);

	void transition();

private:
	GameObjects::GameObject* _shipPlayerOne;
	GameObjects::GameObject* _shipPlayerTwo;
};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_MAINROUNDSTATE_H_ */
