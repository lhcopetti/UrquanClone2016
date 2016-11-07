/*
 * PhysicsComponent.cpp
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/Components/Collision/ColliderComponent.h>
#include <GameMachine/GameObjects/GameObject.h>

#include <iostream>
#include <VectorMath/VectorMath.h>

namespace Components
{

PhysicsComponent::PhysicsComponent(float mass, float maxVelocity, float friction) :
		Component(PHYSICS_COMPONENT),
		_colliderComponent(nullptr), //
		_mass(mass), //
		_forces(sf::Vector2f(0.f, 0.f)), //
		_velocity(sf::Vector2f(0.f, 0.f)), //
		_maxVelocity(maxVelocity), //
		_friction(friction) //
{
}

PhysicsComponent::~PhysicsComponent()
{
	delete _colliderComponent;
	_colliderComponent = nullptr;
}

void PhysicsComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	sf::Vector2f acceleration = _forces / _mass;
	sf::Vector2f accelSecs = acceleration * deltaTime.asSeconds();

	sf::Vector2f position = (_velocity + accelSecs / 2.f)
			* deltaTime.asSeconds();
	gameObject.addPosition(position);

	_velocity += accelSecs;

	if (VectorMath::size(_velocity) > _maxVelocity)
		_velocity = VectorMath::normalize(_velocity) * _maxVelocity;

	if (_friction > 0.f)
		_velocity *= (1 - _friction);
}

sf::Vector2f& PhysicsComponent::getVelocity()
{
	return _velocity;
}

void PhysicsComponent::setVelocity(const sf::Vector2f& velocity)
{
	_velocity = velocity;
}

sf::Vector2f& PhysicsComponent::getForces()
{
	return _forces;
}

void Components::PhysicsComponent::resetForces()
{
	_forces = sf::Vector2f(0.f, 0.f);
}

void PhysicsComponent::setColliderComponent(
		Collision::ColliderComponent* collider)
{
	_colliderComponent = collider;
}

const Collision::ColliderComponent& PhysicsComponent::getCollider() const
{
	return *_colliderComponent;
}

} /* namespace Components */
