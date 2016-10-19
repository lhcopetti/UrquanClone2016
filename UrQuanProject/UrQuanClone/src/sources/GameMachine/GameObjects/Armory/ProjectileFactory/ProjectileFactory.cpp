/*
 * ProjectileFactory.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Armory/ProjectileFactory/ProjectileFactory.h>

namespace Armory
{

ProjectileFactory::ProjectileFactory(Collision::CCategories projectileCategory) :
		_projectileCategory(projectileCategory)
{
}

ProjectileFactory::~ProjectileFactory()
{
}

} /* namespace Armory */
