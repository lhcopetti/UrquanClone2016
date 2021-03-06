/*
 * GameState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMESTATE_GAMESTATE_H_
#define INCLUDES_GAMEMACHINE_GAMESTATE_GAMESTATE_H_

#include <GameMachine/GameObjects/GameObjectCollection.h>
#include <GameMachine/InputControl/InputController.h>
#include <GameMachine/GameStateController.h>

#include <GameMachine/Components/Collision/CollisionManager.h>

#include "SFML/System/Time.hpp"
#include "SFML/Graphics.hpp"

#include <vector>

namespace GameState
{

class GameState
{
//	friend GameMachine::GameStateController;

public:
	GameState(GameMachine::GameStateController& controller);
	virtual ~GameState();

	virtual void onEnter() {}
	virtual void onExit() {}

	void update(const sf::Time& deltaTime);
	virtual void doUpdate(const sf::Time& deltaTime) = 0;

	void draw(sf::RenderWindow& window);

	virtual void doBeforeDraw(sf::RenderWindow& window) const;
	virtual void doDraw(sf::RenderWindow& window);

protected:
	GameMachine::GameStateController& _controller;
	GameObjects::GameObjectCollection _goCollection;
	Collision::CollisionManager _collisionManager;

	Inputs::InputController _inputController;

private:

};

} /* namespace GameState */

#endif /* INCLUDES_GAMEMACHINE_GAMESTATE_GAMESTATE_H_ */
