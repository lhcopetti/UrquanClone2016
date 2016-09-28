/*
 * Ship.h
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEOBJECTS_SHIP_SHIP_H_
#define INCLUDES_GAMEOBJECTS_SHIP_SHIP_H_

#include <GameMachine/GameObjects/GameObject.h>

namespace Components
{
class DrawingComponent;
}

namespace GameObjects
{

class Ship : public GameObject
{
public:
	Ship(Components::DrawingComponent* drawingComponent);
	virtual ~Ship();
};

} /* namespace GameObjects */

#endif /* INCLUDES_GAMEOBJECTS_SHIP_SHIP_H_ */
