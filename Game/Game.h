#include <iostream>

//Frameworks
#include <Leap.h>
#include <SFML/Graphics.hpp>

//Game subclasses
#include "Blockspawner/Blockspawner.h"
#include "Player/Player.h"
#include "ScoreCounter/ScoreCounter.h"

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
        Player _player;
        ScoreCounter _score;

        bool _gameOver;
        
};