/*
 * PhysicsComponent.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/PhysicsComponent.h>

#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{

PhysicsComponent::PhysicsComponent() :
		_velocity(
		{ 0, 0 }), _acceleration(
		{ 0.f, 0.f })
{
}

PhysicsComponent::~PhysicsComponent()
{
}

void PhysicsComponent::update(GameObjects::GameObject& gameObject)
{
	const sf::Vector2f pos = gameObject.getPosition();
	gameObject.setPosition(
	{ pos.x + _velocity.x, pos.y + _velocity.y });
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

void PhysicsComponent::setAcceleration(const sf::Vector2f& acceleration)
{
	_acceleration = acceleration;
}
} /* namespace Components */

