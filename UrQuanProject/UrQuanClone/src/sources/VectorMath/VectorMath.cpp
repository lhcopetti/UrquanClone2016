/*
 * VectorMath.cpp
 *
 *  Created on: 8 de out de 2016
 *      Author: Pichau
 */

#include <VectorMath/VectorMath.h>

#define _USE_MATH_DEFINES
#include <math.h>

namespace VectorMath
{

sf::Vector2f newBySizeAngle(float size, float angle)
{
	float radian = toRadians(angle);
	return sf::Vector2f(cos(radian) * size, sin(radian) * size);
}

float toDegree(float radians)
{
	return 180 * radians / M_PI;
}

float toRadians(float degree)
{
	return degree * M_PI / 180;
}

} /* namespace VectorMath */
