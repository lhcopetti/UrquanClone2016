/*
 * Projectile.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/Projectile.h>

namespace Armory
{

Projectile::Projectile(Components::DrawingComponent* drawingComponent) :
		GameObject(drawingComponent)
{
}

Projectile::~Projectile()
{
}

} /* namespace Armory */
