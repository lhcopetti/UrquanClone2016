/*
 * GameObject.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/GameObject.h>

namespace GameObjects
{

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window) const
{
	_drawingComponent->draw(window);
}

void GameObject::update(const sf::Time& deltaTime)
{
}

void GameObject::setDrawing(Components::DrawingComponent* drawing)
{
	_drawingComponent = std::unique_ptr<Components::DrawingComponent>(drawing);
}

} /* namespace GameState */
