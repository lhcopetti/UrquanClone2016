/*
 * CircleCollidingShape.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_CIRCLECOLLIDINGSHAPE_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_CIRCLECOLLIDINGSHAPE_H_

#include <GameMachine/Components/Collision/Shape/CollidingShape.h>
#include <SFML/System/Vector2.hpp>

namespace Collision
{

class CircleCollidingShape: public CollidingShape
{
public:
	CircleCollidingShape(sf::Vector2f position, float radius);
	virtual ~CircleCollidingShape();

	float getRadius() const;
private:
	float _radius;
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_CIRCLECOLLIDINGSHAPE_H_ */
