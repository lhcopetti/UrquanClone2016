/*
 * BlueDotComponent.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include "GameMachine/Components/BlueDotComponent.h"

namespace Components
{

BlueDotComponent::BlueDotComponent()
{
	// TODO Auto-generated constructor stub

}

BlueDotComponent::~BlueDotComponent()
{
	// TODO Auto-generated destructor stub
}

void BlueDotComponent::update(const GameObjects::GameObject& gameObject)
{

}

void BlueDotComponent::draw(const GameObjects::GameObject& gameObject, sf::RenderWindow& window) const
{
	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(sf::Vector2f(50.f, 50.f));

	window.draw(circle);
}

} /* namespace Components */
