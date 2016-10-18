/*
 * ColliderCategory.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/ColliderCategory.h>

#include <math.h>

namespace Collision
{

ColliderCategory::ColliderCategory(unsigned long bitMask) :
		_categoryBitMask(bitMask)
{

}

ColliderCategory::~ColliderCategory()
{
}

bool ColliderCategory::collidesWith(CCategories category) const
{
	return (_categoryBitMask >> category) & 0x01;
}

void ColliderCategory::add(CCategories category)
{
 	_categoryBitMask |= (unsigned int) pow(2, (unsigned int) category);
}

} /* namespace Collision */
