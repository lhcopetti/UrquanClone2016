/*
 * SeekBehavior.cpp
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Behaviors/Steering/SeekBehavior.h>

#include <GameMachine/GameObjects/GameObject.h>
#include <VectorMath/VectorMath.h>

#include <GameMachine/Components/PhysicsComponent.h>

#include <iostream>

namespace Behavior
{

SeekBehavior::SeekBehavior()
{
	// TODO Auto-generated constructor stub

}

SeekBehavior::~SeekBehavior()
{
	// TODO Auto-generated destructor stub
}

sf::Vector2f SeekBehavior::compute(const sf::Time deltaTime,
		GameObjects::GameObject& origin, GameObjects::GameObject& target)
{
	 sf::Vector2f desiredVel = target.getPosition() - origin.getPosition();
	sf::Vector2f steeringForce;
	desiredVel = VectorMath::normalize(desiredVel);

	desiredVel.x *= origin.getPhysicsComponent()->getMaxVelocity();
	desiredVel.y *= origin.getPhysicsComponent()->getMaxVelocity();

	steeringForce = desiredVel - origin.getPhysicsComponent()->getVelocity();

	std::cout << "Steering force calculated: X: " << steeringForce.x << " Y: " << steeringForce.y << std::endl;

	return steeringForce;
}


} /* namespace Behavior */
