/*
 * BulletFactory.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_BULLETFACTORY_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_BULLETFACTORY_H_

#include <GameMachine/GameObjects/Armory/ProjectileFactory/ProjectileFactory.h>

namespace Armory
{

class BulletFactory : public ProjectileFactory
{
public:
	BulletFactory();
	virtual ~BulletFactory();

	virtual Projectile* createNew();
};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_BULLETFACTORY_H_ */
