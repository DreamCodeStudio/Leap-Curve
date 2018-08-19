#include "Player.h"

void Player::Create(sf::RenderWindow *gameWindow)
{
    //Save pointer to game window
    _gameWindow = gameWindow;

    //Connect leap motion controller
    Leap::Controller _leapController;
    while (!_leapController.isConnected())
    {
        std::cout << "Waiting for connection..." << std::endl;
        sf::sleep(sf::seconds(1.0f));
    }
    std::cout << "Connected!" << std::endl;

    //Set start position
    _position = 50;

    //Add start point
    _line.push_back(new sf::CircleShape);
    _line[_line.size() - 1]->setRadius(1);
    _line[_line.size() - 1]->setFillColor(sf::Color(255, 255, 255));
    _line[_line.size() - 1]->setPosition(sf::Vector2f(50, 500));
}

void Player::Update()
{
    //Get the hand of the player
    Leap::Frame frame = _leapController.frame();
    Leap::Hand hand = frame.hands()[0];
    
    //Now calculate the coresponding ingame position
    float yposition = 1080 - ((hand.stabilizedPalmPosition().y - 60) * 3.6f);

    //The hand position should always be between 0 and 1080
    if (yposition < 0)
    {
        yposition = 0;
    }
    if (yposition > 1080)
    {
        yposition = 1080;
    }
    
    //Draw a point every frame at the current position and interpolate 4 points 
    sf::CircleShape *previousePoint = _line[_line.size() - 1];
    sf::Vector2f currentPosition(_position, yposition);
    sf::Vector2f previousePosition = _line[_line.size() - 1]->getPosition();
    float xdelta = (currentPosition.x - previousePosition.x) / 25.0f;
    float ydelta = (currentPosition.y - previousePosition.y) / 25.0f;

    for (unsigned int i = 0; i < 25; i++)
    {
        _line.push_back(new sf::CircleShape);
        _line[_line.size() - 1]->setRadius(1);
        _line[_line.size() - 1]->setFillColor(sf::Color(255, 255, 255));
        _line[_line.size() - 1]->setPosition(sf::Vector2f(previousePoint->getPosition().x + xdelta * i, 
                                                          previousePoint->getPosition().y + ydelta * i));
    }
    _position += 4;

    //The render function should also center the view here
    this->CenterView();

    //Remove old lines
    this->RemoveOldLine();
}

void Player::Render()
{
    //Render every point 
    for (unsigned int i = 0; i < _line.size(); i++)
    {
        _gameWindow->draw(*_line[i]);
    }
}

/* ############### Private ############## */

void Player::CenterView()
{
    //The view should follow the current point
    sf::View view = _gameWindow->getView();
    view.setCenter(sf::Vector2f(_line[_line.size() - 1]->getPosition().x, view.getCenter().y));
    _gameWindow->setView(view);
}

void Player::RemoveOldLine()
{
    //Remove the old lines
    for (unsigned int i = 0; i < _line.size() / 6; i++)
    {
        if (_line[i]->getPosition().x < _gameWindow->getView().getCenter().x - _gameWindow->getView().getSize().x / 2)
        {
            delete _line[i];
            _line.erase(_line.begin() + i, _line.begin() + i + 1);
            i = 0;
        }
    }
}