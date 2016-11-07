/*
 * ComponentEnum.cpp
 *
 *  Created on: 7 de nov de 2016
 *      Author: LuisCopetti
 */

#include <GameMachine/Components/ComponentEnum.h>

namespace Components
{

#define STRINGFICATION_COMPONENTS(comp) case comp ## _COMPONENT: return #comp "_COMPONENT";

std::string stringComponent(ComponentType type)
{
	switch (type)
	{
	HIGH_ORDER_COMPONENTS(STRINGFICATION_COMPONENTS)
	}

	return "Não foi possível encontrar o tipo de componente para: " + type;
}

#undef STRINGFICATION_COMPONENTS
}
