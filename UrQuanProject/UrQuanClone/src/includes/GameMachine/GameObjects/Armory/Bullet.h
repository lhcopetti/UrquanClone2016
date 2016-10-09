/*
 * Bullet.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_BULLET_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_BULLET_H_

#include <GameMachine/GameObjects/Armory/Projectile.h>

namespace Armory
{

class Bullet: public Armory::Projectile
{
public:
	Bullet(Components::DrawingComponent* drawing);
	virtual ~Bullet();
};

} /* namespace Actions */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_BULLET_H_ */
