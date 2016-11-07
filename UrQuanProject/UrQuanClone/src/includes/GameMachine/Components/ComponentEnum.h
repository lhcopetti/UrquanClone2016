/*
 * ComponentEnum.h
 *
 *  Created on: 7 de nov de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENTENUM_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENTENUM_H_

#include <iostream>
#include <string>

namespace Components
{
typedef unsigned long GameObjectID;

#define HIGH_ORDER_COMPONENTS(code) \
	code(POSITION) \
	code(PHYSICS) \
	code(SHOOTER) \
	code(COLLIDER) \
	code(DRAWING)

#define DEFINE_ENUM_COMPONENTS(comp) comp ## _COMPONENT,

enum ComponentType
{
	HIGH_ORDER_COMPONENTS(DEFINE_ENUM_COMPONENTS)
};

#undef DEFINE_ENUM_COMPONENTS


std::string stringComponent(ComponentType type);

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_COMPONENTENUM_H_ */
