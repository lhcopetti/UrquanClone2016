/*
 * BlueDotComponent.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameMachine/Components/BlueDotComponent.h"

#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{

BlueDotComponent::BlueDotComponent() :
		_circle(10)
{
	_circle.setFillColor(sf::Color::Red);
}

BlueDotComponent::~BlueDotComponent()
{
}

void BlueDotComponent::update(const GameObjects::GameObject& gameObject)
{
	_circle.setPosition(gameObject.getPosition());
}

void BlueDotComponent::draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const
{
	window.draw(_circle);
}

} /* namespace Components */
