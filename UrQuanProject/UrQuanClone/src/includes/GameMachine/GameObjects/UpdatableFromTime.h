/*
 * UpdatableFromTime.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_UPDATABLEFROMTIME_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_UPDATABLEFROMTIME_H_


#include "SFML/System/Time.hpp"

class UpdatableFromTime
{
public:
	virtual ~UpdatableFromTime() {}

	virtual void update(const sf::Time& deltaTime) = 0;
};


#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_UPDATABLEFROMTIME_H_ */
