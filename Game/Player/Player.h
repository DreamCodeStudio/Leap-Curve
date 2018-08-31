#include <iostream>
#include <ctime>

//Frameworks
#include <Leap.h>
#include <SFML/Graphics.hpp>

class Player
{
    public:

        void Create(sf::RenderWindow *gameWindow);

        void Update();
        void Render();

        void Reset();
        sf::CircleShape GetPlayerPoint();

    private:

        void CenterView();
        void RemoveOldLine();
        void UpdateColor();

        Leap::Controller _leapController;
        sf::RenderWindow *_gameWindow;
        sf::Color _drawColor;

        std::vector<sf::CircleShape*> _line;
        int _position;
};