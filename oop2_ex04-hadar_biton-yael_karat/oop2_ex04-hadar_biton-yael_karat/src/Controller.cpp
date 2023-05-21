
#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "6 - color", sf::Style::Close | sf::Style::Titlebar)
{
    m_background.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT + MENU_HEIGHT });
    m_background.setFillColor(sf::Color(219, 254, 255));
   
}

void Controller::run()
{
    m_game.init();
    print();
    while (m_window.isOpen())
    {
        
        isGameRunning = true;
        isHelpWindowOpen = false;

        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
                handleClick(event.mouseButton);
                print();
                break;
            }
            
        }
    }
}

void Controller::print()
{
    sf::Font font;
    font.loadFromFile("arial.ttf");

    m_window.clear(sf::Color(0, 0, 0));
    if (m_game.getIsGameOver() || m_game.getIsWin()) {
        auto title = sf::Text();
        title.setCharacterSize(40);
        title.setFont(font);
        title.setPosition(260, 150);
        title.setFillColor(sf::Color::Black);
        if (m_game.getIsGameOver()) {
            title.setString("Game Over!");
        }
        else {
            title.setString("You WON!");
        }
        m_window.draw(title);

    }

    else {
        m_newGameButton = sf::RectangleShape();
        m_newGameButton.setSize(sf::Vector2f(170, 100));
        m_newGameButton.setFillColor(sf::Color::Color(238, 238, 228));
        m_window.draw(m_newGameButton);

        auto buttonText = sf::Text();
        buttonText.setCharacterSize(30);
        buttonText.setFont(font);
        buttonText.setPosition(300, 300);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setString("Starting a new game");
        m_window.draw(buttonText);
    }
    
    m_window.draw(m_background);
    m_board.drawBoard(m_window, m_game.getUserRoot(), m_board.getVisitedNodes());
    drawMenu();
    drawColorsButtons();
    m_window.display();
}


void Controller::handleClick(const sf::Event::MouseButtonEvent& event) {

    if (m_quitButton.getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y }))) {
        m_window.close();
    }

    else if (m_newGameButton.getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y }))) {
        
    }

    else if (m_RedButton.getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y }))) {
        //updateColorAndSaveNeighbors();
        m_background.setFillColor(sf::Color(234, 234, 123));
    }
}

void Controller::drawColorsButtons() {
  
    m_RedButton = sf::RectangleShape();
    m_RedButton.setSize(sf::Vector2f(40, 40));
    m_RedButton.setPosition(sf::Vector2f(250, 715));
    m_RedButton.setOutlineThickness(1);
    m_RedButton.setOutlineColor(sf::Color::Black);
    m_RedButton.setFillColor(sf::Color::Red);
    m_window.draw(m_RedButton);

    m_BlueButton = sf::RectangleShape();
    m_BlueButton.setSize(sf::Vector2f(40, 40));
    m_BlueButton.setPosition(sf::Vector2f(320, 715));
    m_BlueButton.setOutlineThickness(1);
    m_BlueButton.setOutlineColor(sf::Color::Black);
    m_BlueButton.setFillColor(sf::Color::Blue);
    m_window.draw(m_BlueButton);

    m_GreenButton = sf::RectangleShape();
    m_GreenButton.setSize(sf::Vector2f(40, 40));
    m_GreenButton.setPosition(sf::Vector2f(390, 715));
    m_GreenButton.setOutlineThickness(1);
    m_GreenButton.setOutlineColor(sf::Color::Black);
    m_GreenButton.setFillColor(sf::Color::Green);
    m_window.draw(m_GreenButton);

    m_YellowButton = sf::RectangleShape();
    m_YellowButton.setSize(sf::Vector2f(40, 40));
    m_YellowButton.setPosition(sf::Vector2f(460, 715));
    m_YellowButton.setOutlineThickness(1);
    m_YellowButton.setOutlineColor(sf::Color::Black);
    m_YellowButton.setFillColor(sf::Color::Yellow);
    m_window.draw(m_YellowButton);

    m_PinkButton = sf::RectangleShape();
    m_PinkButton.setSize(sf::Vector2f(40, 40));
    m_PinkButton.setPosition(sf::Vector2f(530, 715));
    m_PinkButton.setOutlineThickness(1);
    m_PinkButton.setOutlineColor(sf::Color::Black);
    m_PinkButton.setFillColor(sf::Color::Color(234, 63, 247));
    m_window.draw(m_PinkButton);

    m_purpleButton = sf::RectangleShape();
    m_purpleButton.setSize(sf::Vector2f(40, 40));
    m_purpleButton.setPosition(sf::Vector2f(600, 715));
    m_purpleButton.setOutlineThickness(1);
    m_purpleButton.setOutlineColor(sf::Color::Black);
    m_purpleButton.setFillColor(sf::Color::Color(115, 43, 245));
    m_window.draw(m_purpleButton);
   
}

void Controller::drawMenu() {

    sf::Font font;
    font.loadFromFile("arial.ttf");

    m_quitButton = sf::RectangleShape();
    m_quitButton.setSize(sf::Vector2f(80, 50));
    m_quitButton.setPosition(sf::Vector2f(370, 25));
    m_quitButton.setOutlineThickness(1);
    m_quitButton.setOutlineColor(sf::Color::Black);
    m_quitButton.setFillColor(sf::Color::Color(238, 238, 228));
    m_window.draw(m_quitButton);

    auto quitText = sf::Text();
    quitText.setCharacterSize(20);
    quitText.setFont(font);
    quitText.setPosition(390, 35);
    quitText.setFillColor(sf::Color::Black);
    quitText.setString("Quit");
    m_window.draw(quitText);

    m_newGameButton = sf::RectangleShape();
    m_newGameButton.setSize(sf::Vector2f(80, 50));
    m_newGameButton.setPosition(sf::Vector2f(470, 25));
    m_newGameButton.setOutlineThickness(1);
    m_newGameButton.setOutlineColor(sf::Color::Black);
    m_newGameButton.setFillColor(sf::Color::Color(238, 238, 228));
    m_window.draw(m_newGameButton);

    auto newGameText = sf::Text();
    newGameText.setCharacterSize(20);
    newGameText.setFont(font);
    newGameText.setPosition(490, 35);
    newGameText.setFillColor(sf::Color::Black);
    newGameText.setString("New");
    m_window.draw(newGameText);

}