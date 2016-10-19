/*
 * ProjectileFactory.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_H_

#include <GameMachine/Components/Collision/ColliderCategory.h>

namespace Armory
{

class Projectile;

class ProjectileFactory
{
public:
	ProjectileFactory(Collision::CCategories projectileCategory);
	virtual ~ProjectileFactory();

	virtual Projectile* createNew() = 0;

protected:
	const Collision::CCategories _projectileCategory;
};

} /* namespace Armory */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_H_ */
