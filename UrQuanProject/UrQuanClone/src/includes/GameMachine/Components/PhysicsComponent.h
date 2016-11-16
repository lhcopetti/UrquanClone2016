/*
 * PhysicsComponent.h
 *
 *  Created on: 6 de out de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_PHYSICSCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_PHYSICSCOMPONENT_H_

#include <GameMachine/Components/Component.h>
#include <SFML/System.hpp>

namespace GameObjects
{
class GameObject;
}

namespace Collision
{
class ColliderComponent;
}

namespace Components
{

class PhysicsComponent : public Component
{
public:
	PhysicsComponent(float mass, float maxVelocity, float friction);
	virtual ~PhysicsComponent();

	void resetForces();
	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);

	sf::Vector2f& getForces();
	sf::Vector2f& getAcceleration();
	sf::Vector2f& getVelocity();

	float getMaxVelocity();

	void setVelocity(const sf::Vector2f& velocity);
	void setAcceleration(const sf::Vector2f& velocity);

	void setColliderComponent(Collision::ColliderComponent* collider);
	const Collision::ColliderComponent& getCollider() const;

private:
	Collision::ColliderComponent* _colliderComponent;

	float _mass;

	sf::Vector2f _forces;
	sf::Vector2f _velocity;

	float _maxVelocity;
	float _friction;
};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_PHYSICSCOMPONENT_H_ */
