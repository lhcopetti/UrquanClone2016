/*
 * TimeBomb.h
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_GEOMETRY_TIMEBOMB_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_GEOMETRY_TIMEBOMB_H_

#include <GameMachine/GameObjects/GameObject.h>
#include <SFML/System/Time.hpp>

namespace Geometry
{

class TimeBomb : public GameObjects::GameObject
{
public:
	TimeBomb(Components::DrawingComponent* drawingComponent, sf::Time timeToExplode);
	virtual ~TimeBomb();

	virtual void update(const sf::Time& deltaTime);

private:
	sf::Time _timeToExplode;
	sf::Time _counter;
};

} /* namespace Geometry */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_GEOMETRY_TIMEBOMB_H_ */
