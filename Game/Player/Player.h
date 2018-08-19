#include <iostream>

//Frameworks
#include <Leap.h>
#include <SFML/Graphics.hpp>

class Player
{
    public:

        void Create(sf::RenderWindow *gameWindow);

        void Update();
        void Render();

    private:

        void CenterView();
        void RemoveOldLine();

        Leap::Controller _leapController;
        sf::RenderWindow *_gameWindow;

        std::vector<sf::CircleShape*> _line;
        int _position;
};