/*
 * RectDrawingComponent.cpp
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/RectDrawingComponent.h>

#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{

RectDrawingComponent::RectDrawingComponent(sf::Color color, sf::Vector2f pos,
		sf::Vector2f size)
{
	_shape.setFillColor(color);
	_shape.setPosition(pos);
	_shape.setSize(size);
}

RectDrawingComponent::~RectDrawingComponent()
{
}

void RectDrawingComponent::update(const sf::Time& deltaTime,
		GameObjects::GameObject& gameObject)
{
	const sf::Vector2f pos = gameObject.getPosition();
	_shape.setPosition(pos);
}

void RectDrawingComponent::draw(const GameObjects::GameObject& gameObject,
		sf::RenderWindow& window) const
{
	window.draw(_shape);
}

} /* namespace Geometry */
