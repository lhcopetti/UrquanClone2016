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

float size(const sf::Vector2f& vector)
{
	return sqrt(sizeSqrt(vector));
}

float sizeSqrt(const sf::Vector2f& vector)
{
	return pow(vector.x, 2) + pow(vector.y, 2);
}

sf::Vector2f normalize(const sf::Vector2f& vector)
{
	return vector / size(vector);
}

void normalize(sf::Vector2f& vector)
{
	vector /= size(vector);
}

sf::Vector2f rotate(const sf::Vector2f& vector, float angle)
{
	float radians = toRadians(angle);
	float sinAng = sin(radians);
	float cosAng = cos(radians);

	return sf::Vector2f(cosAng * vector.x - sinAng * vector.y,
			sinAng * vector.x + cosAng * vector.y);
}

} /* namespace VectorMath */

