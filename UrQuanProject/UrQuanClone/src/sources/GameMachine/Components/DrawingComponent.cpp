/*
 * DrawingComponent.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/DrawingComponent.h>

namespace Components
{

DrawingComponent::DrawingComponent()
{
}

DrawingComponent::~DrawingComponent()
{
}

void DrawingComponent::update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject)
{

}

void DrawingComponent::sendMessage(const std::string& msg)
{
	/* Default empty implementation */
}

} /* namespace Components */

