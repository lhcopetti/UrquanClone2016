/*
 * ShapeCollider.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_SHAPECOLLIDER_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_SHAPECOLLIDER_H_

#include <GameMachine/Components/Collision/Shape/CircleCollidingShape.h>
#include <GameMachine/Components/Collision/Shape/RectangleCollidingShape.h>

namespace Collision
{

class ShapeCollider
{
public:
	ShapeCollider();
	virtual ~ShapeCollider();

	static bool checkCollision(const CircleCollidingShape* circle1, const CircleCollidingShape* circle2);
	static bool checkCollision(const RectangleCollidingShape* rectangle1, const RectangleCollidingShape* rectangle2);
	static bool checkCollision(const RectangleCollidingShape* rectangle, const CircleCollidingShape* circle);
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_SHAPECOLLIDER_H_ */
