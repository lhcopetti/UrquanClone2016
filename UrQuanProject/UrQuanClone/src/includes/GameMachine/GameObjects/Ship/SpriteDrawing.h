/*
 * ShipDrawing.h
 *
 *  Created on: 27 de set de 2016
 *      Author: LuisCopetti
 */

#ifndef INCLUDES_GAMEOBJECTS_SHIP_SHIPDRAWING_H_
#define INCLUDES_GAMEOBJECTS_SHIP_SHIPDRAWING_H_

#include <GameMachine/Components/DrawingComponent.h>

namespace sf
{
class Sprite;
class Texture;
}

namespace GameObjects
{

class SpriteDrawing: public Components::DrawingComponent
{
public:
	SpriteDrawing(const std::string& resourcePath, float angleOffset = 0.f);
	virtual ~SpriteDrawing();

	virtual void update(const sf::Time& deltaTime, GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject,
			sf::RenderWindow& window) const;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;

	float _angleOffset;
};

} /* namespace GameObjects */

#endif /* INCLUDES_GAMEOBJECTS_SHIP_SHIPDRAWING_H_ */
