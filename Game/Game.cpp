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

    //Set start value
    _gameOver = false;
}

void Game::Run()
{
    //Update and render the whole game
    this->HandleEvents();

    if (_gameOver == false)
    {
        this->Update();
        this->Render();
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            _gameOver = false;
            _player.Reset();
            _blocksp.Reset();
        }
    }
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

    if (_blocksp.CheckCollision(_player.GetPlayerPoint()))
    {
        std::cout << "Collision detected!" << std::endl;
        _gameOver = true;
    }
}

void Game::Render()
{
    _gameWindow.clear();

    //Render the whole game
    _blocksp.Render();
    _player.Render();

    _gameWindow.display();
}