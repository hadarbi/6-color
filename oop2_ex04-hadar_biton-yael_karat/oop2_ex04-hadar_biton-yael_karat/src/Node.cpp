#include "Node.h"

#include <algorithm>

Node::Node(const sf::Color& node_color) : color(node_color) {}


void Node::addNeighbor(Node* node, std::vector<Node*> neighborList) {
    neighborList.push_back(node);

}

/*void Node::updateColorAndSaveNeighbors(const sf::Color& targetColor, Node* root) {
    if (color != targetColor) {
        for (Node* neighbor : neighbors) {
            if (std::find(saved.begin(), saved.end(), neighbor) == saved.end() &&
                neighbor->getColor() == targetColor) {
                saved.push_back(neighbor);
                neighbor->updateColorAndSaveNeighbors(targetColor, root);
            }
        }
    }

    if (color != targetColor) {
        color = targetColor;
        saved.push_back(root);5
    }
}*/

std::vector<Node*>* Node::getUserNeighbors() {
    return m_user_neighbors;
}

std::vector<Node*>* Node::getComputerNeighbors() {
    return m_computer_neighbors;
}

sf::Color Node::getColor() const {
    return color;
}

sf::Vector2f Node::getPosition() const {
    return position;
}

void Node::setPosition(const sf::Vector2f& position) {
    this->position = position;
}