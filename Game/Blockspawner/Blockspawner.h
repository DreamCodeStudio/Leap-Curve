#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>

class Blockspawner
{
    public:

        void Create();
        void Update();
        void Render(sf::RenderWindow *gameWindow);

    private:

        std::vector<sf::RectangleShape*> _blocks;
        sf::Clock _blockClock;
        int _position;

};