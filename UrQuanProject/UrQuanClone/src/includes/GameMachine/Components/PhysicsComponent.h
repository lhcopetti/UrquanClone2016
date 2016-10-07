/*
 * PhysicsComponent.h
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_PHYSICSCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_PHYSICSCOMPONENT_H_

#include <SFML/System/Vector2.hpp>

namespace GameObjects
{
class GameObject;
}

namespace Components
{

class PhysicsComponent
{
public:
	PhysicsComponent();
	virtual ~PhysicsComponent();

	virtual void update(GameObjects::GameObject& gameObject);

	sf::Vector2f& getVelocity();
	sf::Vector2f& getAcceleration();

	void setVelocity(const sf::Vector2f& velocity);
	void setAcceleration(const sf::Vector2f& velocity);

private:
	sf::Vector2f _velocity;
	sf::Vector2f _acceleration;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_PHYSICSCOMPONENT_H_ */
