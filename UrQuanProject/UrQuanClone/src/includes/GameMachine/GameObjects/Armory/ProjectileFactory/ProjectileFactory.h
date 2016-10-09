/*
 * ProjectileFactory.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_H_

namespace Armory
{

class Projectile;

class ProjectileFactory
{
public:
	ProjectileFactory();
	virtual ~ProjectileFactory();

	virtual Projectile* createNew() = 0;
};

} /* namespace Armory */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_H_ */
