#include "Blockspawner.h"

void Blockspawner::Create()
{
    srand(time(NULL));
    _position = 300;
}

void Blockspawner::Update()
{
    if (_blockClock.getElapsedTime().asMilliseconds() > sf::milliseconds(1000).asMilliseconds())
    {
        //Top block
        _blocks.push_back(new sf::RectangleShape);
        _blocks[_blocks.size() - 1]->setFillColor(sf::Color(0, 200, 0));
        _blocks[_blocks.size() - 1]->setSize(sf::Vector2f(10, rand() % 830));
        _blocks[_blocks.size() - 1]->setPosition(sf::Vector2f(_position, 0));

        //Bot block
        _blocks.push_back(new sf::RectangleShape);
        _blocks[_blocks.size() - 1]->setFillColor(sf::Color(0, 200, 0));
        _blocks[_blocks.size() - 1]->setSize(sf::Vector2f(10, 830 - _blocks[_blocks.size() - 2]->getGlobalBounds().height));
        _blocks[_blocks.size() - 1]->setPosition(sf::Vector2f(_position, _blocks[_blocks.size() - 2]->getGlobalBounds().height + 250));

        _blockClock.restart();
        _position = _position + 350;
    }
}

void Blockspawner::Render(sf::RenderWindow *gameWindow)
{
    for (unsigned int i = 0; i < _blocks.size(); i++)
    {
        gameWindow->draw(*_blocks[i]);
    }
}