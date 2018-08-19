#include "Blockspawner.h"

void Blockspawner::Create(sf::RenderWindow *gameWindow)
{
    //Save pointer to game window
    _gameWindow = gameWindow;

    //Set random seed and start position
    srand(time(NULL));
    _position = 300;

    this->SpawnBlock();
    this->SpawnBlock();
    this->SpawnBlock();    
}

void Blockspawner::Update()
{
    //Spawn a block every second
    if (_blockClock.getElapsedTime().asMilliseconds() > sf::milliseconds(1000).asMilliseconds())
    {
        this->SpawnBlock();
    }

    //Remove old blocks which are out of the screen bounds
    this->RemoveOldBlocks();
}

void Blockspawner::Render()
{
    //Render all blocks to the window
    for (unsigned int i = 0; i < _blocks.size(); i++)
    {
        _gameWindow->draw(*_blocks[i]);
    }
}

/* ############### Private ############### */
void Blockspawner::SpawnBlock()
{
    //Top block
    _blocks.push_back(new sf::RectangleShape);
    _blocks[_blocks.size() - 1]->setFillColor(sf::Color(0, 200, 0));
    _blocks[_blocks.size() - 1]->setSize(sf::Vector2f(40, rand() % 830));
    _blocks[_blocks.size() - 1]->setPosition(sf::Vector2f(_position, 0));

    //Bot block
    _blocks.push_back(new sf::RectangleShape);
    _blocks[_blocks.size() - 1]->setFillColor(sf::Color(0, 200, 0));
    _blocks[_blocks.size() - 1]->setSize(sf::Vector2f(40, 830 - _blocks[_blocks.size() - 2]->getGlobalBounds().height));
    _blocks[_blocks.size() - 1]->setPosition(sf::Vector2f(_position, _blocks[_blocks.size() - 2]->getGlobalBounds().height + 250));

    _blockClock.restart();
    _position = _position + 240;
}

void Blockspawner::RemoveOldBlocks()
{
    for (unsigned int i = 0; i < _blocks.size(); i++)
    {
        if (_blocks[i]->getPosition().x < _gameWindow->getView().getCenter().x - 40 - _gameWindow->getView().getSize().x / 2)
        {
            delete _blocks[i];
            _blocks.erase(_blocks.begin() + i, _blocks.begin() + i + 1);
            i = 0;
        }
    }
}