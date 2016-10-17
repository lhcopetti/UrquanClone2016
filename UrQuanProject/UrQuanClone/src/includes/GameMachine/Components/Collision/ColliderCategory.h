/*
 * ColliderCategory.h
 *
 *  Created on: 17 de out de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDERCATEGORY_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDERCATEGORY_H_

namespace Collision
{

#define HIGH_ORDER_COLLIDER_CATEGORY(code) \
	code(WALL) \
	code(PROJECTILE_PLAYERONE)



#define HIGH_ORDER_DEFINE_ENUM(x) CC_##x,
enum CCategories
{
	HIGH_ORDER_COLLIDER_CATEGORY(HIGH_ORDER_DEFINE_ENUM)
};
#undef HIGH_ORDER_DEFINE_ENUM


class ColliderCategory
{
public:
	ColliderCategory();
	virtual ~ColliderCategory();

	bool collidesWith(CCategories category) const;

private:
	unsigned long _categoryBitMask;
};

} /* namespace Collision */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COLLISION_COLLIDERCATEGORY_H_ */
