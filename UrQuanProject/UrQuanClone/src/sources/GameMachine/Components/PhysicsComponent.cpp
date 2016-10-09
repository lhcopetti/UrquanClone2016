/*
 * PhysicsComponent.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/GameObjects/GameObject.h>

#include <iostream>
#include <VectorMath/VectorMath.h>

namespace Components
{

PhysicsComponent::PhysicsComponent() :
		_mass(1), //
		_forces(sf::Vector2f(0.f, 0.f)), //
		_acceleration(sf::Vector2f(0.f, 0.f)), //
		_velocity(sf::Vector2f(0.f, 0.f))
{
}

PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	_acceleration = _forces / _mass;
	sf::Vector2f accelSecs = _acceleration * deltaTime.asSeconds();

	sf::Vector2f position = (_velocity + accelSecs / 2.f)
			* deltaTime.asSeconds();
	gameObject.addPosition(position);

	_velocity += accelSecs;

	std::cout << "Velocity: " << VectorMath::size(_velocity) << std::endl;

	const float maxVelociy = 250.f;

	if (VectorMath::size(_velocity) > maxVelociy)
		_velocity = VectorMath::normalize(_velocity) * 250.f;
//	_velocity.x = std::min(15.f, _velocity.x);
//	_velocity.y = std::min(15.f, _velocity.y);
}

sf::Vector2f& PhysicsComponent::getVelocity()
{
	return _velocity;
}

sf::Vector2f& PhysicsComponent::getAcceleration()
{
	return _acceleration;
}

void PhysicsComponent::setVelocity(const sf::Vector2f& velocity)
{
	_velocity = velocity;
}

sf::Vector2f& PhysicsComponent::getForces()
{
	return _forces;
}

void PhysicsComponent::setAcceleration(const sf::Vector2f& acceleration)
{
	_acceleration = acceleration;
}

void Components::PhysicsComponent::resetForces()
{
	_forces = sf::Vector2f(0.f, 0.f);
}

} /* namespace Components */
