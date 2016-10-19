/*
 * SquareBulletFactory.h
 *
 *  Created on: 18 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_SQUAREBULLETFACTORY_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_SQUAREBULLETFACTORY_H_

#include <GameMachine/GameObjects/Armory/ProjectileFactory/ProjectileFactory.h>

namespace Armory
{

class SquareBulletFactory: public ProjectileFactory
{
public:
	SquareBulletFactory(Collision::CCategories projectileCategory);
	virtual ~SquareBulletFactory();

	virtual Projectile* createNew();
};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILEFACTORY_SQUAREBULLETFACTORY_H_ */
