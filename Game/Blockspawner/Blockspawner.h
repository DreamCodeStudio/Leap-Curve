#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class Blockspawner
{
    public:

        void Create(sf::RenderWindow *gameWindow);
        void Update();
        void Render();

        bool CheckCollision(sf::CircleShape player);
        void Reset();

    private:

        void SpawnBlock();
        void RemoveOldBlocks();

        sf::RenderWindow *_gameWindow;
        std::vector<sf::RectangleShape*> _blocks;
        sf::Clock _blockClock;
        int _position;

};