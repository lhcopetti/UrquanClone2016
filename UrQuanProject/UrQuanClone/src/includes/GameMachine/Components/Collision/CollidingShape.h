/*
 * CollidingShape.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDINGSHAPE_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDINGSHAPE_H_

namespace Collision
{

enum CollidingShapeType
{
	AABB_RECTANGLE,
	CIRCLE
};

class CollidingShape
{
public:
	CollidingShape();
	virtual ~CollidingShape();
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDINGSHAPE_H_ */
