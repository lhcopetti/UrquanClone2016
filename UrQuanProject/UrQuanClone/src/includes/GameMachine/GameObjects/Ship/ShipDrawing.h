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

class ShipDrawing: public Components::DrawingComponent
{
public:
	ShipDrawing(const std::string& resourcePath);
	virtual ~ShipDrawing();

	virtual void update(const GameObjects::GameObject& gameObject);
	virtual void draw(const GameObjects::GameObject& gameObject,
			sf::RenderWindow& window) const;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::CircleShape _circle;
};

} /* namespace GameObjects */

#endif /* INCLUDES_GAMEOBJECTS_SHIP_SHIPDRAWING_H_ */