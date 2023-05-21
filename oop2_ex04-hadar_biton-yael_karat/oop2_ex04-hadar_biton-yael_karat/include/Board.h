#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iosfwd>
#include <cstdint>
#include <algorithm>

#include <random>
#include <set>
#include "Macros.h"
#include "Node.h"
#include "Game.h"

class Board
{
public:
    Board();
    void drawBoard(sf::RenderWindow& window, Node* node, std::set<Node*>& visitedNodes);
    std::set<Node*>& getVisitedNodes();

private:
    std::set<Node*> visitedNodes;
};
