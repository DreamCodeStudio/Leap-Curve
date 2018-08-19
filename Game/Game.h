#include <iostream>

//Frameworks
#include <Leap.h>
#include <SFML/Graphics.hpp>

//Game subclasses
#include "Blockspawner/Blockspawner.h"

class Game
{
    public:

        Game();

        void Run();
        bool IsOpen();

    private:

        void HandleEvents();
        void Update();
        void Render();

        sf::RenderWindow _gameWindow;
        Leap::Controller _leapController;

        //Game classes
        Blockspawner _blocksp;
};