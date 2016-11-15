/*
 * MissileFactory.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_MISSILEFACTORY_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_MISSILEFACTORY_H_

#include <GameMachine/GameObjects/Armory/ProjectileFactory/ProjectileFactory.h>

namespace Armory
{

class MissileFactory: public ProjectileFactory
{
public:
	MissileFactory(Collision::CCategories projectileCategory);
	virtual ~MissileFactory();

	virtual Projectile* createNew();
};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_MISSILEFACTORY_H_ */
