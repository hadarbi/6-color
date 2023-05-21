
#include "Game.h"

Game::Game() {}

void Game::init()
{
    // init nodes here instead of in the header file
    std::vector<std::vector<Node*>> nodes;
    nodes.clear();
    sf::Vector2f pos = { ODD_DISTANCE, 120 };

    // Create hexagon shape for each board position
    for (size_t i = 0; i < BOARD_LEN; i++)
    {
        std::vector<Node*> nodes_line = std::vector<Node*>();
        for (size_t j = 0; j < BOARD_LEN; j++)
        {
            // Create a Node object with a random color
            Node* node = new Node(generateRandomColor());

            // Set the position of the node
            node->setPosition(pos);
            nodes_line.push_back(node);

            // Create hexagon shape and set its properties
            pos.x += HEXAGON_DISTANCE;

        }
        // Add the node to the nodes vector
        nodes.push_back(nodes_line);
        pos.y += HEXAGON_DISTANCE;
        if (i % 2 == 0)
            pos.x = EVEN_DISTANCE;
        else
            pos.x = ODD_DISTANCE;
    }
  
    user_root = nodes[BOARD_LEN - 1][0];
    computer_root = nodes[0][BOARD_LEN - 1];
    
    // set nigbers to each node
    for (size_t i = BOARD_LEN-1; i > 0; i--)
    {
        for (size_t j = 0; j < BOARD_LEN-1; j++) {
            Node* node = nodes[i][j];
            std::vector<Node*>& user_neighbors = *(node->getUserNeighbors());
            if (j + 1 < BOARD_LEN)
                user_neighbors.push_back(nodes[i][j + 1]);
            if (i - 1 >= 0)
                user_neighbors.push_back(nodes[i - 1][j]);
            if (i - 1 >= 0 && j + 1 < BOARD_LEN)
                user_neighbors.push_back(nodes[i - 1][j + 1]);

        }
    }
}

sf::Color Game::generateRandomColor() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 5);

    int colorIndex = dis(gen);

    switch (colorIndex) {
    case 0:
        return sf::Color::Red;
    case 1:
        return sf::Color::Blue;
    case 2:
        return sf::Color::Green;
    case 3:
        return sf::Color::Yellow;
    case 4:
        return sf::Color(234, 63, 247);
    case 5:
        return sf::Color(115, 43, 245);
    }
}

Node* Game::getUserRoot() {
    return user_root;
}

bool Game::getIsGameOver() const {
    return isGameOver;
}

void Game::setIsGameOver(bool value) {
    isGameOver = value;
}

bool Game::getIsWin() const {
    return isWin;
}

void Game::setIsWin(bool value) {
    isWin = value;
}