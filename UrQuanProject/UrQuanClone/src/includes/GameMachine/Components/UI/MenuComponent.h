/*
 * MenuComponent.h
 *
 *  Created on: 24 de set de 2016
 *      Author: Pichau
 */

#ifndef INCLUDES_GAMEMACHINE_COMPONENTS_UI_MENUCOMPONENT_H_
#define INCLUDES_GAMEMACHINE_COMPONENTS_UI_MENUCOMPONENT_H_

#include <GameMachine/GameObjects/GameObject.h>
#include <GameMachine/GameObjects/Inputs/InputHandler.h>

#include <GameMachine/InputControl/InputController.h>
#include <GameMachine/Components/UI/Options/AbstractOption.h>

#include <vector>


namespace UI
{

class MenuComponent: public Inputs::InputHandler
{
public:
	MenuComponent(GameMachine::InputController& inputController, std::vector<AbstractOption*> options, sf::Vector2f pos);
	virtual ~MenuComponent();

	virtual void handleInput(int handlerData);

	void reset();

	bool isMenuFinished() const;
	AbstractOption* getSelected();

private:

	void updateOptions(const unsigned int currentIndex, const unsigned int index);

	GameMachine::InputController& _inputController;

	std::vector<AbstractOption*> _options;

	sf::Vector2f _pos;

	int _currentIndex;

	bool _menuFinished;
	AbstractOption* _selectedOption;


};

} /* namespace Components */

#endif /* INCLUDES_GAMEMACHINE_COMPONENTS_UI_MENUCOMPONENT_H_ */
