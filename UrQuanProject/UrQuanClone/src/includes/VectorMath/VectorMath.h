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

float dist(const sf::Vector2f& p1, const sf::Vector2f& p2);
float distSqr(const sf::Vector2f& p1, const sf::Vector2f& p2);

sf::Vector2f normalize(const sf::Vector2f& vector);

sf::Vector2f rotate(const sf::Vector2f& vector, float angle);

} /* namespace VectorMath */

#endif /* INCLUDES_VECTORMATH_VECTORMATH_H_ */
