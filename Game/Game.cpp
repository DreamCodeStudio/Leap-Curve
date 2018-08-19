#include "Game.h"

Game::Game()
{
    //Create game window
    _gameWindow.create(sf::VideoMode(1920, 1080), "LeapCurve");
    _gameWindow.setFramerateLimit(60);

    //Connect leap motion controller
    Leap::Controller _leapController;
    while (!_leapController.isConnected())
    {
        std::cout << "Waiting for connection..." << std::endl;
        sf::sleep(sf::seconds(1.0f));
    }
    std::cout << "Connected!" << std::endl;

    //Create blockspawner class
    _blocksp.Create();
}

void Game::Run()
{
    //Update and render the whole game
    this->HandleEvents();
    this->Update();
    this->Render();
}

bool Game::IsOpen()
{
    return _gameWindow.isOpen();
}

/* ############# Private ############# */

void Game::HandleEvents()
{
    //Get events and handle the window
    sf::Event event;
    while(_gameWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _gameWindow.close();
            return;
        }
    }
}

void Game::Update()
{
    //Update the game
    _blocksp.Update();
}

void Game::Render()
{
    _gameWindow.clear();

    //Render the whole game
    _blocksp.Render(&_gameWindow);

    _gameWindow.display();
}