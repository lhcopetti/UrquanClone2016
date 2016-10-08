/*
 * VectorMath.h
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_VECTORMATH_VECTORMATH_H_
#define INCLUDES_VECTORMATH_VECTORMATH_H_

#include <SFML/System.hpp>

namespace VectorMath
{

sf::Vector2f newBySizeAngle(float size, float angle);

float toRadians(float degree);
float toDegree(float radians);

} /* namespace VectorMath */

#endif /* INCLUDES_VECTORMATH_VECTORMATH_H_ */
