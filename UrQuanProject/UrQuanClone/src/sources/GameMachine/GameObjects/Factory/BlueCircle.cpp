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
	// TODO Auto-generated constructor stub

}

BlueCircle::~BlueCircle()
{
	// TODO Auto-generated destructor stub
}

GameObjects::GameObject* BlueCircle::newBlueCircle()
{
	GameObjects::GameObject* gameObject = new GameObjects::GameObject(new BlueDotComponent);
	return gameObject;
}

} /* namespace Components */
