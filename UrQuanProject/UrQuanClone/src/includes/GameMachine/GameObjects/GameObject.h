/*
 * GameObject.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_
#define SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_

#include <GameMachine/GameObjects/UpdatableFromTime.h>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>
#include <GameMachine/GameObjects/Actions/ActionExecutor.h>

#include "SFML/Graphics.hpp"

namespace Components
{
class DrawingComponent;
class PhysicsComponent;
class ShooterComponent;
class BehaviorComponent;
}

namespace Collision
{
class ColliderComponent;
}

namespace GameObjects
{

class GameObjectCollection;

class GameObject: public UpdatableFromTime, public Inputs::InputHandler
{
	friend GameObjectCollection;

public:
	GameObject(Components::DrawingComponent* drawingComponent = nullptr,
			sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
	virtual ~GameObject();

	void update(const sf::Time& deltaTime);
	virtual void doUpdate(const sf::Time& deltaTime);

	void draw(sf::RenderWindow& window) const;

	void setPosition(const sf::Vector2f& newPos);
	void addPosition(const sf::Vector2f& position);
	const sf::Vector2f& getPosition() const;

	void setOrientation(float newOrientation);
	float getOrientation() const;

	virtual void handleInput(int userData);

	void setHealth(int newHealth);
	int getHealth() const;
	
	void setMaxHealth(float newMaxHealth);
	float getMaxHealth() const;


	bool isAlive() const;
	void die();

	void setPhysicsComponent(Components::PhysicsComponent* physics);
	Components::PhysicsComponent* getPhysicsComponent();

	void setShooterComponent(Components::ShooterComponent* shooter);
	Components::ShooterComponent* getShooterComponent();

	void setColliderComponent(Collision::ColliderComponent* collider);
	Collision::ColliderComponent* getColliderComponent();

	void setBehaviorComponent(Components::BehaviorComponent* behavior);
	Components::BehaviorComponent* getBehaviorComponent();

	void pushAction(Actions::Action* action);

	void reproduce(GameObject* gameObject);
	std::vector<GameObject*>& getProduced();

	GameObjectCollection* getParent() const;

	void onCollisionWith(GameObject& other);

protected:

	std::unique_ptr<Components::DrawingComponent> _drawingComponent;
	Components::PhysicsComponent* _physicsComponent;
	Components::ShooterComponent* _shooterComponent;
	Components::BehaviorComponent* _behaviorComponent;
	Collision::ColliderComponent* _colliderComponent;


	sf::Vector2f _pos;
	float _orientation;

	float _health;
	float _maxHealth;

private:
	GameObjectCollection* _parent;

	Actions::ActionExecutor _executor;

	std::vector<GameObject*> _reproduction;
};

} /* namespace GameState */

#endif /* SOURCES_GAMEMACHINE_GAMEOBJECT_GAMEOBJECT_H_ */
