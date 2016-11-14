/*
 * ActionBundle.cpp
 *
 *  Created on: 13 de nov de 2016
 *      Author: Pichau
 */

#include <GameMachine/GameObjects/Actions/Decorations/ActionBundle.h>

namespace Actions
{

ActionBundle::ActionBundle()
{
}

ActionBundle::~ActionBundle()
{
	for (unsigned int i = 0; i < _bundle.size(); i++)
		delete _bundle[i];
}

bool ActionBundle::canExecute(GameObjects::GameObject& gameObject)
{
	return std::all_of(  //
			_bundle.begin(), //
			_bundle.end(),  //
			[&gameObject](Action* action) //
			{	 //
				return action->canExecute(gameObject);//
			}); //
}

bool ActionBundle::execute(GameObjects::GameObject& gameObject)
{
	return std::all_of(  //
			_bundle.begin(), //
			_bundle.end(),  //
			[&gameObject](Action* action) //
			{	 //
				return action->execute(gameObject);//
			}); //
}

void ActionBundle::setContext(GameObjects::GameObject* context)
{
	std::for_each(_bundle.begin(), _bundle.end(), [&context](Action* action)
	{	action->setContext(context);});
}

void ActionBundle::add(Action* action)
{
	_bundle.push_back(action);
}

} /* namespace Actions */
