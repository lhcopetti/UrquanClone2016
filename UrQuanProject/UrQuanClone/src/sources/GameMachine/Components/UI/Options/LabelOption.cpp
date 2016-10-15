/*
 * LabelOption.cpp
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#include <GameMachine/Components/UI/Options/LabelOption.h>

namespace UI
{

LabelOption::LabelOption(sf::Vector2f size, Components::DrawingComponent* drawingComponent) :
		AbstractOption(size, drawingComponent)
{
}

LabelOption::~LabelOption()
{
}

} /* namespace UI */
