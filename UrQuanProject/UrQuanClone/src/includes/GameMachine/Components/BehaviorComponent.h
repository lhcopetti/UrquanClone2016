/*
 * BehaviorComponent.h
 *
 *  Created on: 15 de nov de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_BEHAVIORCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_BEHAVIORCOMPONENT_H_

#include <GameMachine/Components/Component.h>

namespace Behavior
{
class Behavior;
}

namespace Components
{


class BehaviorComponent: public Component
{
public:
	BehaviorComponent(Behavior::Behavior* behavior);
	virtual ~BehaviorComponent();

	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);

private:
	Behavior::Behavior* _behavior;
};

} /* namespace Behaviors */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_BEHAVIORCOMPONENT_H_ */
