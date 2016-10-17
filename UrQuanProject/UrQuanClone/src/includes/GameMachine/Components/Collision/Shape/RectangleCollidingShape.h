/*
 * RectangleCollidingShape.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_RECTANGLECOLLIDINGSHAPE_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_RECTANGLECOLLIDINGSHAPE_H_

#include <GameMachine/Components/Collision/Shape/CollidingShape.h>
#include <SFML/System/Vector2.hpp>

namespace Collision
{

class RectangleCollidingShape: public CollidingShape
{
public:
	RectangleCollidingShape(sf::Vector2f position, sf::Vector2f size);
	virtual ~RectangleCollidingShape();

	const sf::Vector2f& getSize() const;

private:
	sf::Vector2f _size;
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_SHAPE_RECTANGLECOLLIDINGSHAPE_H_ */
