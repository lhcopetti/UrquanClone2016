/*
 * CollidingShape.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDINGSHAPE_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDINGSHAPE_H_

#include <SFML/System/Vector2.hpp>

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
	CollidingShape(CollidingShapeType shapeType, const sf::Vector2f& position);
	virtual ~CollidingShape();

	CollidingShapeType getType() const;

	const sf::Vector2f& getPosition() const;
	void setPosition(const sf::Vector2f& position);

private:
	sf::Vector2f _position;
	const CollidingShapeType _shapeType;
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDINGSHAPE_H_ */
