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
	// TODO Auto-generated constructor stub

}

GameObject::~GameObject()
{
	// TODO Auto-generated destructor stub
}

void GameObject::draw(sf::RenderWindow& window) const
{
	_drawingComponent->draw(window);
}

void GameObject::setDrawing(Components::DrawingComponent* drawing)
{
	_drawingComponent = std::unique_ptr<Components::DrawingComponent>(drawing);
}

} /* namespace GameState */
