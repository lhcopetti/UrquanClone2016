/*
 * Missile.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_MISSILE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_MISSILE_H_

#include <GameMachine/GameObjects/Armory/Projectile.h>

namespace Armory
{

class Missile: public Projectile
{
public:
	Missile(Components::DrawingComponent* drawing);
	virtual ~Missile();
};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_MISSILE_H_ */
