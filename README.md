# Urquan Clone - Project 2016

This project was implemented for the Game Development Specialization course I am taking right now on PUCPR. The objective is to manually implement the physics and behavior calculation for a spaceship based game, similar to UrquanMaster. 
If you do not know, or never heard about the Urquan game, below are some relevant information about the game:

Please, take look at their website:
[Urquan website](http://sc2.sourceforge.net/)

Or even, take some time to watch a short gameplay :
[Youtube Video](https://www.youtube.com/watch?v=o7_rm_l7WvI)

I am not getting into details, but basically these are the macro steps for playing this game:

## Urquan Master Objectives

![alt-text][urquan-menu]

1. Make your team
    
    Making your team means you are supposed to choose from a variety of different ships, each with its own special and unique abilities.

1. Wait for your adversary
    
    As you probably imagined, you shall have a worthy adversary. He will also assemble his team from his available pool of space ships.

1. The Game stars
    
    ![alt-text][urquan-game]
    
    When the game starts, the first two ships of each team is put in a somewhere in space arena where you fight each other. 

1. Kill you Enemy
    
   You may be wondering why would I go to the trouble of choosing a team if I am playing with a single ship. Well, I hope you did not expect to control them all at once!
   What actually happens, though, is that once one of the ship dies it gets promptly replaced by another integrant of your team. So that another round starts between a new team member and the winning from the previous round.

1. Empty your adversary's pocket
    
    After dwelling long enough, you or your adversary will end up short of spaceships and have no backup anymore. That is when the game ends and a overall winner is declared. Remember, do not only win the battle. You should also win the war.
    
# Back to the Project itself

Before going any further, I wish to shatter your expectations that you probably have for this game. I don't want you to wrongfully imagine that this is an actual Urquan Clone implementation (even though the repository's name states so):

### Screenshots

#### Game Menu
![alt-text][game-menu]
#### GameRound
![alt-text][game-round]
#### GameWinner
![alt-text][game-winner]

Notice the background colors? Yes, they were arbitrarily picked and you may be thinking that was the result of some kind of glitch on the loading of the assets? You poor fool. I really don't care for that, sorry!
Also, does that brighty colors make you uncomfortable? I don't even aim for that effect, but I feel like I have a natural talent to bring that up in people with my games.


# Personal Highlights:

I am getting into the habit of documenting my games, so here are some of my personal highlights while making this one in particlar:

### Grading

First, the most important: *The grading part*. 

We are supposed to pinpoint where in our game the physics was handled. Mine, lives in:

[PhysicsComponent](./UrQuanProject/UrQuanClone/src/sources/GameMachine/Components/PhysicsComponent.cpp)

[SteeringBehavior](./UrQuanProject/UrQuanClone/src/includes/GameMachine/GameObjects/Behaviors/SteeringBehavior.cpp)


### Component Approach

I decided to use a heavily based component approach for the implementation of this demo. I actually got pretty satisfied with the results and the decoupling arising from its use. The only thing I regret was not taking the time to refactor the GameObject entirely. I was following the approach of not trying to optimize early, so I simply hardcoded components to the GameObject as they were being created, as show below:

```
std::unique_ptr<Components::DrawingComponent> _drawingComponent;
Components::PhysicsComponent* _physicsComponent;
Components::ShooterComponent* _shooterComponent;
Components::BehaviorComponent* _behaviorComponent;
Collision::ColliderComponent* _colliderComponent;
```

If I were to ever revist this game, for say, learning puposes, I would definitely tackle this issue first. The idea is to come closer to the implementation mentioned in a side note on the chapter of the amazing [Game Programming Patterns](http://gameprogrammingpatterns.com/component.html) book. The so called 'Entity Component System'.


### Vector Math
It was actually really cool to implement the vector operations myself, although I kinda wished to have taken the time to write my own Vector to implement the functions on top instead of using SFML's.

### Action

This is another "framework" that I implemented that really paid off. It worked amazingly well, and it is hard to imagine any future game where I will not use even a slightly varition of this technique. For example, instead of calling GameObject::getHit(int damage), I am able to push an action on it called DamageAction. The most amazing thing for me is that it works like a messaging system, but the message is also executed in the context of the receiving gameObject. Testing each implementation would be extremely easy, but for some reason I was not into that back then.

![alt-text][[game-actions]

Another example: The 'output' of the BehaviorComponent is a force that should be applied to the GameObject so that it reroutes its course in favor of some direction (maybe to chase another ship). Instead of the behavior checking for the physicsComponent on the GameObject, it simply pushes an ApplyForce action that takes the responsibility of checking these kind of prerequisites and applying the force in the end.

![alt-text][game-behavior]

### GameStates

This was the first time I implemented a Menu for a game. I have never fiddled before with the concepts of implementing separate Scenes. However, it was a really good experience to have the ability to transition between a GameMenu that has its own collection of GameObjects and the GameRound itself with all its flying killing missiles seamlessly. I wonder how I could implement and embed a scene within another one and make it behave like some sort of a mini-map or another world view. Huh!

![alt-text][game-state]

### Input Controller

Another thing that took some time to implement was a binding mechanism for keyboard presses/releases/double presses and the GameObject actions. What that means is that the Input and the Action resulting from that event would already be tied together by a mapping made beforehand. The GameObject itself would only have to act upon the action it receives.

You can see that in action for the [Credits File](./UrQuanProject/UrQuanClone/src/sources/GameMachine/GameState/CreditsState.cpp):

To ease the declaration of these bindings I also came up with a simple DSL builder.

*The binding*:

![alt-text][game-input-binding]

*The acting*:

![alt-text][game-input-acting]



[urquan-menu]: https://github.com/lhcopetti/UrquanClone2016/blob/develop/DOC/UrquanMasters_Menu.PNG
[urquan-game]: https://github.com/lhcopetti/UrquanClone2016/blob/develop/DOC/UrquanMasters_Gameplay.PNG
[game-menu]: https://github.com/lhcopetti/UrquanClone2016/blob/develop/DOC/Clone_MainMenu.PNG
[game-round]: https://github.com/lhcopetti/UrquanClone2016/blob/develop/DOC/Clone_GameRound.png
[game-winner]: https://github.com/lhcopetti/UrquanClone2016/blob/develop/DOC/Clone_Credits.png

[game-actions]: https://github.com/lhcopetti/UrquanClone2016/blob/develop/DOC/Actions.PNG
[game-state]: 
[game-behavior]:
[game-input-binding]:
[game-input-acting]:
