/*
 * BlueCircle.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_BLUECIRCLE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_BLUECIRCLE_H_

#include "GameMachine/GameObjects/GameObject.h"

namespace Components
{

class BlueCircle
{
public:
	BlueCircle();
	virtual ~BlueCircle();

	static GameObjects::GameObject* newBlueCircle();
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_FACTORY_BLUECIRCLE_H_ */
