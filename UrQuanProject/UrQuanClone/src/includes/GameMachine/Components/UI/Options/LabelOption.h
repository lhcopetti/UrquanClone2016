/*
 * LabelOption.h
 *
 *  Created on: 25 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_UI_OPTIONS_LABELOPTION_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_UI_OPTIONS_LABELOPTION_H_

#include <GameMachine/Components/UI/Options/AbstractOption.h>
#include <SFML/Graphics.hpp>

namespace UI
{

class LabelOption : public AbstractOption
{
public:
	LabelOption(sf::Vector2f size, Components::DrawingComponent* drawingComponent);
	virtual ~LabelOption();

};

} /* namespace UI */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_UI_OPTIONS_LABELOPTION_H_ */
