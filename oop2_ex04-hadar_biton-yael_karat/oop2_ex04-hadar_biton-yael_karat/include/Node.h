#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Macros.h"

class Node {
public:
    Node(const sf::Color& color);
    void addNeighbor(Node* node, std::vector<Node*> neighborList);
    //void updateColorAndSaveNeighbors(const sf::Color& targetColor, Node* root);
    sf::Vector2f getPosition() const;
    sf::Color getColor() const;
    std::vector<Node*>* getUserNeighbors();
    std::vector<Node*>* getComputerNeighbors();
    void setPosition(const sf::Vector2f& position);


private:
    sf::Color color;
    sf::Vector2f position;
    std::vector<Node*>* m_user_neighbors = new std::vector<Node*>();
    std::vector<Node*>* m_computer_neighbors = new std::vector<Node*>();


};