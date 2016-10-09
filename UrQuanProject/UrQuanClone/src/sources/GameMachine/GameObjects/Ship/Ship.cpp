/*
 * Ship.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Ship/Ship.h>
#include <GameMachine/GameObjects/Ship/ShipInput.h>

#include <GameMachine/Components/PhysicsComponent.h>
#include <iostream>

#include <GameMachine/GameObjects/Actions/ApplyForceAction.h>
#include <GameMachine/GameObjects/Actions/Rotation/RotateByAction.h>
#include <GameMachine/GameObjects/Actions/ShootAction.h>

#include <VectorMath/VectorMath.h>

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
	if (nullptr == _physicsComponent)
		return;
}

void GameObjects::Ship::handleInput(int userData)
{
	if (userData == ShipInput::SHIP_THRUST)
	{
		sf::Vector2f velocityVector = VectorMath::newBySizeAngle(300.f,
				_orientation);
		pushAction(new Actions::ApplyForceAction(velocityVector));
	}
	else if (userData == ShipInput::SHIP_ROTATE_LEFT)
	{
		pushAction(new Actions::RotateByAction(-4.f));
	}
	else if (userData == ShipInput::SHIP_ROTATE_RIGHT)
	{
		pushAction(new Actions::RotateByAction(+4.f));
	}
	else if (userData == ShipInput::SHIP_SHOOT)
	{
		pushAction(new Actions::ShootAction());
	}

}

} /* namespace GameObjects */
