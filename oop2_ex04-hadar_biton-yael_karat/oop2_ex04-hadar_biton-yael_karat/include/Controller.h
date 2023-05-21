#pragma once
#include <set>
#include <SFML/Graphics.hpp>
#include "Node.h"
#include "Board.h"
#include "Macros.h"
#include "Game.h"

class Controller
{
public:
    Controller();
    void run();
    
private:
    void print();
    void drawMenu();
    void handleClick(const sf::Event::MouseButtonEvent& event);
    void drawColorsButtons();

    sf::RectangleShape m_playButton;
    sf::RectangleShape m_newGameButton;
    sf::RectangleShape m_background;
    sf::RectangleShape m_quitButton;

    sf::RenderWindow m_window;
    Game m_game;
    Board m_board;
    bool isGameRunning;
    bool isHelpWindowOpen;

    sf::RectangleShape m_RedButton;
    sf::RectangleShape m_BlueButton;
    sf::RectangleShape m_YellowButton;
    sf::RectangleShape m_GreenButton;
    sf::RectangleShape m_PinkButton;
    sf::RectangleShape m_purpleButton;
};
