#include "ScoreCounter.h"

void ScoreCounter::Create(sf::RenderWindow *gameWindow)
{
    //Save pointer to game window
    _gameWindow = gameWindow;

    //Load font
    _font.loadFromFile("Assets/Fonts/OpenSans-Light.ttf");
    _scoreText.setFont(_font);
    _scoreText.setFillColor(sf::Color(255, 255, 255));
    _scoreText.setCharacterSize(25);
}

void ScoreCounter::Update()
{
    //Get score
    int score = _gameWindow->getView().getCenter().x;

    //Convert into string
    std::string strScore;
    std::stringstream str;
    str << score;
    str >> strScore;

    //Set score as text
    _scoreText.setString(strScore);

    //Move text so it is always displayed in the top left corner
    _scoreText.setPosition(sf::Vector2f(_gameWindow->getView().getCenter().x - _gameWindow->getView().getSize().x / 2 + 10,
                                        10));
}

void ScoreCounter::Render()
{
    _gameWindow->draw(_scoreText);
}