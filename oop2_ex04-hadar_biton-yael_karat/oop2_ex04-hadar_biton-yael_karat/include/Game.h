#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Macros.h"
#include "Board.h"
#include "Node.h"

class Game {
public:
    Game();
    void init();
    bool getIsGameOver() const;
    void setIsGameOver(bool value);
    bool getIsWin() const;
    void setIsWin(bool value);
    Node* getUserRoot();
    //Node* getComputerRoot();

private:
    
    sf::Color generateRandomColor();
    bool isGameOver;
    bool isWin;
    Node* user_root;
    Node* computer_root;
   
};