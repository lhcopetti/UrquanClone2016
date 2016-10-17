/*
 * ColliderCategory.cpp
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/Collision/ColliderCategory.h>

namespace Collision
{

ColliderCategory::ColliderCategory() :
		_categoryBitMask(0x00)
{
}

ColliderCategory::~ColliderCategory()
{
}

bool ColliderCategory::collidesWith(CCategories category) const
{
	return (_categoryBitMask >> category) & 0x01;
}

} /* namespace Collision */
