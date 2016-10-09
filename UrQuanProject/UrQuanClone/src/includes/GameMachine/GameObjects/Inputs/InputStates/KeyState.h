/*
 * KeyState.h
 *
 *  Created on: 11 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATE_H_
#define INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATE_H_

#include <SFML/Window/Keyboard.hpp>
#include "SFML/System/Time.hpp"

#include <GameMachine/GameObjects/Inputs/InputType.h>

#define DOUBLE_TAP_KEY_INTERVAL_MS 150

namespace Inputs
{

class KeyState
{
public:
	KeyState(sf::Keyboard::Key key, InputType type, sf::Time = sf::Time());
	virtual ~KeyState();

	virtual void onEnter() {}
	virtual void onExit() {}
	KeyState* update(const sf::Time& deltaTime);
	virtual KeyState* doUpdate(const sf::Time& deltaTime) = 0;

	InputType type() const;
	sf::Keyboard::Key key() const;
	const sf::Time& getTimeElapsed() const;

protected:
	const sf::Keyboard::Key _key;
	sf::Time _timeElapsed;

private:
	const InputType _type;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATE_H_ */
