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

void BlueDotComponent::draw(sf::RenderWindow& window) const
{
	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color::White);
	circle.setPosition(sf::Vector2f(50.f, 50.f));

	window.draw(circle);
}

} /* namespace Components */
