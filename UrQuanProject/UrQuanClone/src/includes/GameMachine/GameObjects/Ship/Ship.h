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

enum ShipType
{
	SHIP_Soldier74, SHIP_GAIJIN
};

class Ship : public GameObject
{
public:
	Ship(Components::DrawingComponent* drawingComponent);
	virtual ~Ship();

	virtual void doUpdate(const sf::Time& deltaTime);

	virtual void handleInput(int userData);
};

} /* namespace GameObjects */

#endif /* INCLUDES_GAMEOBJECTS_SHIP_SHIP_H_ */
