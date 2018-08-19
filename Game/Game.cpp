#include "Game.h"

Game::Game()
{
    //Create game window
    _gameWindow.create(sf::VideoMode(1920, 1080), "LeapCurve");
    _gameWindow.setFramerateLimit(60);

    //Create player class
    _player.Create(&_gameWindow);

    //Create blockspawner class
    _blocksp.Create(&_gameWindow);
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
    _player.Update();
}

void Game::Render()
{
    _gameWindow.clear();

    //Render the whole game
    _blocksp.Render();
    _player.Render();

    _gameWindow.display();
}