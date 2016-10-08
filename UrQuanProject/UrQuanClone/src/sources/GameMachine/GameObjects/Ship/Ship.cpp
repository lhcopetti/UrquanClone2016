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

#include <GameMachine/GameObjects/Actions/SetVelocityAction.h>
#include <GameMachine/GameObjects/Actions/Rotation/RotateByAction.h>

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
	std::cout << "Ship command received: "
			<< GameObjects::shipInputString((ShipInput) userData) << std::endl;

	if (userData == ShipInput::SHIP_THRUST)
	{
		std::cout << "Orientation: " << _orientation << std::endl;
		sf::Vector2f velocityVector = VectorMath::newBySizeAngle(1.f, _orientation);
		std::cout << "Printing vel vector. X: " << velocityVector.x << " Y: " << velocityVector.y << std::endl;
		pushAction(new Actions::SetVelocityAction(velocityVector));
	}
//	else if (userData == ShipInput::SHIP_THRUST_RELEASE)
//	{
//		pushAction(new Actions::SetVelocityAction(
//		{ -0.f, 0.f }));
//	}
	else if (userData == ShipInput::SHIP_ROTATE_LEFT)
	{
		pushAction(new Actions::RotateByAction(-25.f));
	}
	else if (userData == ShipInput::SHIP_ROTATE_RIGHT)
	{
		pushAction(new Actions::RotateByAction(+25.f));
	}
}

} /* namespace GameObjects */
