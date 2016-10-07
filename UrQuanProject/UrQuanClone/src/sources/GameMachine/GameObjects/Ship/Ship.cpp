/*
 * Ship.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Ship/Ship.h>

#include <GameMachine/Components/PhysicsComponent.h>

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

	if (nullptr == _physicsComponent)
			return;

	_physicsComponent->setVelocity(sf::Vector2f(2.f, 0.f));
}

} /* namespace GameObjects */
