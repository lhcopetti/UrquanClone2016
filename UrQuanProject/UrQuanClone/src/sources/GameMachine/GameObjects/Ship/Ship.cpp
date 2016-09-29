/*
 * Ship.cpp
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/GameObjects/Ship/Ship.h>

namespace GameObjects
{

Ship::Ship(Components::DrawingComponent* drawingComponent) :
		GameObject(drawingComponent)
{
}

Ship::~Ship()
{
}

} /* namespace GameObjects */
