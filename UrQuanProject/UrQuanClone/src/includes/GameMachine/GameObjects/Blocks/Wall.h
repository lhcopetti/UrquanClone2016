/*
 * Wall.h
 *
 *  Created on: 16 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_BLOCKS_WALL_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_BLOCKS_WALL_H_

#include <GameMachine/GameObjects/GameObject.h>

namespace GameObjects
{

class Wall : public GameObject
{
public:
	Wall();
	virtual ~Wall();
};

} /* namespace GameObjects */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_BLOCKS_WALL_H_ */
