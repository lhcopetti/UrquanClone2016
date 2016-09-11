/*
 * Ship.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Ship/Ship.h>

namespace GameObjects
{

Ship::Ship(Components::DrawingComponent* drawingComponent) :
		GameObject(drawingComponent)
{
}

Ship::~Ship()
{
}


void GameObjects::Ship::doUpdate(const sf::Time& deltaTime)
{
	_orientation += 1;
}

} /* namespace GameObjects */
