/*
 * Component.cpp
 *
 *  Created on: 9 de out de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/Component.h>

namespace Components
{

Component::Component(ComponentType componentType) :
		_type(componentType)
{
}

Component::~Component()
{
}

ComponentType Component::getType()
{
	return _type;
}

std::string Component::toString()
{
	return Components::stringComponent(_type);
}

} /* namespace Components */
