/*
 * Bullet.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/Bullet.h>

namespace Armory
{

Bullet::Bullet(Components::DrawingComponent* drawing) :
		Projectile(drawing)
{
}

Bullet::~Bullet()
{
}

} /* namespace Actions */
