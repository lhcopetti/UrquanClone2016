/*
 * GameObject.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObject.h>
#include "GameMachine/Components/DrawingComponent.h"

namespace GameObjects
{

GameObject::GameObject(Components::DrawingComponent* drawingComponent, sf::Vector2f pos) :
		_drawingComponent(std::unique_ptr<Components::DrawingComponent>(drawingComponent)),
		_pos(pos)
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
	if (nullptr == _drawingComponent)
		return;

	_drawingComponent->update(*this);
}

void GameObject::setPosition(const sf::Vector2f& newPos)
{
	_pos = newPos;
}

} /* namespace GameState */