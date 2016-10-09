/*
 * Projectile.h
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILE_H_

#include <GameMachine/GameObjects/GameObject.h>

namespace Armory
{

class Projectile : public GameObjects::GameObject
{
public:
	Projectile(Components::DrawingComponent* drawingComponent);
	virtual ~Projectile();
};

} /* namespace Armory */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_ARMORY_PROJECTILE_H_ */
