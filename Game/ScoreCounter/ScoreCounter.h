#include <iostream>
#include <sstream>

//Frameworks
#include <Leap.h>
#include <SFML/Graphics.hpp>

class ScoreCounter
{
    public:

        void Create(sf::RenderWindow *gameWindow);

        void Update();
        void Render();

    private:

        sf::RenderWindow *_gameWindow;

        sf::Font _font;
        sf::Text _scoreText;
};