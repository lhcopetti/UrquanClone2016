/*
 * GameObject.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObject.h>
#include <GameMachine/GameObjects/Inputs/InputAction.h>
#include "GameMachine/Components/DrawingComponent.h"

namespace GameObjects
{

GameObject::GameObject(Components::DrawingComponent* drawingComponent,
		sf::Vector2f pos) :
		_drawingComponent(
				std::unique_ptr<Components::DrawingComponent>(
						drawingComponent)), _alive(true), _pos(pos), _orientation(
				false)
{
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window) const
{
	if (nullptr == _drawingComponent)
		return;

	_drawingComponent->draw(*this, window);
}

void GameObject::update(const sf::Time& deltaTime)
{
	doUpdate(deltaTime);

	if (nullptr == _drawingComponent)
		return;

	_drawingComponent->update(*this);
}

void GameObject::doUpdate(const sf::Time& deltaTime)
{
	/* Default Empty Implementation */
}

void GameObject::setPosition(const sf::Vector2f& newPos)
{
	_pos = newPos;
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

} /* namespace GameState */

