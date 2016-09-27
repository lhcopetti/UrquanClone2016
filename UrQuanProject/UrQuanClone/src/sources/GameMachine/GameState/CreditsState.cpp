/*
 * CreditsState.cpp
 *
 *  Created on: 26 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameState/CreditsState.h>

namespace GameState
{

CreditsState::CreditsState(GameMachine::GameStateController& controller) :
	GameState(controller)
{
}

CreditsState::~CreditsState()
{
}

void CreditsState::doUpdate(const sf::Time& deltaTime)
{
}

void CreditsState::doBeforeDraw(sf::RenderWindow& window) const
{
	window.clear(sf::Color::Green);
}

} /* namespace GameMachine */
