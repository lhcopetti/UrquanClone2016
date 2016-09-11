/*
 * BlueDotComponent.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_COMPONENTS_BLUEDOTCOMPONENT_H_
#define SOURCES_GAMEMACHINE_COMPONENTS_BLUEDOTCOMPONENT_H_

#include <GameMachine/Components/DrawingComponent.h>

namespace Components
{

class BlueDotComponent : public DrawingComponent
{
public:
	BlueDotComponent();
	virtual ~BlueDotComponent();

	virtual void draw(sf::RenderWindow& window) const;
};

} /* namespace Components */

#endif /* SOURCES_GAMEMACHINE_COMPONENTS_BLUEDOTCOMPONENT_H_ */
