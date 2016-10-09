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

float size(const sf::Vector2f& vector);
float sizeSqrt(const sf::Vector2f& vector);

sf::Vector2f normalize(const sf::Vector2f& vector);
//void normalize(sf::Vector2f& vector);

} /* namespace VectorMath */

#endif /* INCLUDES_VECTORMATH_VECTORMATH_H_ */
