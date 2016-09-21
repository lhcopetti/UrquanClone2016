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

namespace Inputs
{

class KeyState
{
public:
	KeyState(sf::Keyboard::Key key, InputType type);
	virtual ~KeyState();

	virtual void onEnter() {}
	virtual void onExit() {}
	virtual KeyState* update(const sf::Time& deltaTime) = 0;

	InputType type() const;
	sf::Keyboard::Key key() const;

protected:
	const sf::Keyboard::Key _key;

private:
	const InputType _type;
};

} /* namespace GameMachine */

#endif /* INCLUDES_GAMEMACHINE_GAMEOBJECTS_INPUTS_INPUTSTATES_KEYSTATE_H_ */
