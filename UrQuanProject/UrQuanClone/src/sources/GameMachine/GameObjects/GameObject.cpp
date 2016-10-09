/*
 * GameObject.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObject.h>
#include <GameMachine/GameObjects/Inputs/InputAction.h>

#include <GameMachine/Components/DrawingComponent.h>
#include <GameMachine/Components/PhysicsComponent.h>
#include <GameMachine/Components/ShooterComponent.h>

namespace GameObjects
{

GameObject::GameObject(Components::DrawingComponent* drawingComponent,
		sf::Vector2f pos) :
		_drawingComponent(
				std::unique_ptr<Components::DrawingComponent>(
						drawingComponent)), //
		_physicsComponent(nullptr),  //
		_shooterComponent(nullptr), _alive(true), //
		_pos(pos), //
		_orientation(false) //
{
}

GameObject::~GameObject()
{
	if (nullptr != _physicsComponent)
	{
		delete _physicsComponent;
		_physicsComponent = nullptr;
	}

	if (nullptr != _shooterComponent)
	{
		delete _shooterComponent;
		_shooterComponent = nullptr;
	}
}

void GameObject::draw(sf::RenderWindow& window) const
{
	if (nullptr == _drawingComponent)
		return;

	_drawingComponent->draw(*this, window);
}

void GameObject::update(const sf::Time& deltaTime)
{
	if (nullptr != _physicsComponent)
		_physicsComponent->resetForces();

	_executor.update(*this);

	if (nullptr != _shooterComponent)
		_shooterComponent->update(deltaTime, *this);

	if (nullptr != _physicsComponent)
		_physicsComponent->update(deltaTime, *this);

	doUpdate(deltaTime);

	if (nullptr != _drawingComponent)
		_drawingComponent->update(deltaTime, *this);

}

void GameObject::doUpdate(const sf::Time& deltaTime)
{
	/* Default Empty Implementation */
}

void GameObject::setPosition(const sf::Vector2f& newPos)
{
	_pos = newPos;
}

void GameObject::addPosition(const sf::Vector2f& position)
{
	_pos += position;
}

const sf::Vector2f& GameObject::getPosition() const
{
	return _pos;
}

void GameObject::handleInput(int userData)
{
}

bool GameObject::isAlive() const
{
	return _alive;
}

void GameObject::setOrientation(float newOrientation)
{
	_orientation = newOrientation;
}

float GameObject::getOrientation() const
{
	return _orientation;
}

void GameObject::setPhysicsComponent(Components::PhysicsComponent* physics)
{
	_physicsComponent = physics;
}

Components::PhysicsComponent* GameObject::getPhysicsComponent()
{
	return _physicsComponent;
}

void GameObject::pushAction(Actions::Action* action)
{
	_executor.push(action);
}

void GameObjects::GameObject::setShooterComponent(
		Components::ShooterComponent* shooter)
{
	_shooterComponent = shooter;
}

Components::ShooterComponent* GameObjects::GameObject::getShooterComponent()
{
	return _shooterComponent;
}

void GameObject::reproduce(GameObject* gameObject)
{
	_reproduction.push_back(gameObject);
}

std::vector<GameObject*>& GameObject::getProduced()
{
	return _reproduction;
}

} /* namespace GameState */
