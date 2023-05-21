#include "Board.h"

Board::Board(){}

void Board::drawBoard(sf::RenderWindow& window, Node* node, std::set<Node*>& visitedNodes) {
    
    if (visitedNodes.count(node) > 0) {
        // Node has already been visited, exit the recursive call
        return;
    }

    visitedNodes.insert(node);

    sf::CircleShape hexagon(HEXAGON_RADIUS, 6);
    hexagon.setOutlineThickness(2);
    hexagon.setOutlineColor(sf::Color(0, 0, 0, 255));
    hexagon.setFillColor(node->getColor());
    hexagon.setPosition(node->getPosition());
    window.draw(hexagon);

    std::vector<Node*>* node_user_neighbors = node->getUserNeighbors();
    for (Node* neighbor : *node_user_neighbors) {
      drawBoard(window, neighbor, visitedNodes);
    }
      
}

std::set<Node*>& Board::getVisitedNodes() {
    return visitedNodes;
}