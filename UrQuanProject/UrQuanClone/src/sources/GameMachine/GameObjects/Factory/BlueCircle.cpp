/*
 * BlueCircle.cpp
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Factory/BlueCircle.h>
#include "GameMachine/Components/BlueDotComponent.h"

namespace Components
{

BlueCircle::BlueCircle()
{
}

BlueCircle::~BlueCircle()
{
}

GameObjects::GameObject* BlueCircle::newBlueCircle()
{
	GameObjects::GameObject* gameObject = new GameObjects::GameObject(new BlueDotComponent);
	gameObject->setPosition(sf::Vector2f(50.f, 50.f));
	return gameObject;
}

} /* namespace Components */
