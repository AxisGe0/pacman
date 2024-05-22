#include "Ghost.h"

// Default constructor for Ghost
Ghost::Ghost() {}

// Constructor for Ghost with parameters
Ghost::Ghost(sf::RenderWindow& window, int gs, int x, int y, std::string color) : gridSize(gs) {
    cellSize = window.getSize().x / gridSize;
    if (!ghostTexture.loadFromFile("images/ghost_" + color + ".png")) {
        std::cerr << "Error: Failed to load ghost texture file." << std::endl;
    } else {
        // Set ghost texture, origin, scale, and initial position
        ghost.setTexture(ghostTexture);
        ghost.setOrigin(ghostTexture.getSize().x / 2, ghostTexture.getSize().y / 2);
        ghost.setScale(cellSize / ghost.getLocalBounds().width, cellSize / ghost.getLocalBounds().height);
        ghost.setPosition(y * cellSize + (cellSize / 2), x * cellSize + (cellSize / 2));
        std::cout << "Ghost installed lol" << std::endl;
    }
}

// Draws the ghost on the game window
void Ghost::draw(sf::RenderWindow& window) {
    window.draw(ghost);
}

// Moves the ghost in the specified direction
bool Ghost::move(int direction, Maze maze, float time) {
    float fSpeed = time * speed;
    sf::Vector2f ghostMov = getMovement(change, fSpeed);
    sf::Vector2f ghostPos = ghost.getPosition() + ghostMov;
    int gridX = ghostPos.x / cellSize;
    int gridY = ghostPos.y / cellSize;

    // Check if the new position is not a wall
    if (!maze.isWall(gridX, gridY)) {
        sf::Vector2f Gpos(ghostPos.x, ghostPos.y);
        if (change == 0 || change == 2) {
            Gpos = sf::Vector2f(ghostPos.x, gridY * cellSize + (cellSize / 2));
        } else if (change == 1 || change == 3) {
            Gpos = sf::Vector2f(gridX * cellSize + (cellSize / 2), ghostPos.y);
        } else {
            Gpos = sf::Vector2f(gridX * cellSize + (cellSize / 2), gridY * cellSize + (cellSize / 2));
        }
        ghost.setPosition(Gpos);
    } else {
        change = rand() % 4; // Change direction if new position is a wall
    }
    return true;
}

// Sets the position of the ghost
void Ghost::setPosition(const sf::Vector2f& newPos) {
    ghost.setPosition(newPos);
}

// Getter for the position of the ghost
sf::Vector2f Ghost::getPosition() const {
    return ghost.getPosition();
}

// Calculates the movement vector for the ghost based on direction
sf::Vector2f Ghost::getMovement(int change, float fSpeed) {
    sf::Vector2f ghostMov(0.0f, 0.0f);
    switch (change) {
        case 0:
            ghostMov.x = fSpeed; // Move right
            break;
        case 1:
            ghostMov.y = fSpeed; // Move down
            break;
        case 2:
            ghostMov.x = -fSpeed; // Move left
            break;
        case 3:
            ghostMov.y = -fSpeed; // Move up
            break;
    }
    return ghostMov;
}

// Getter for the speed of the ghost
float Ghost::getSpeed() {
    return speed;
}

// Checks if the ghost collides with Pacman
bool Ghost::checkDeath(Pacman p) {
    sf::Vector2f PacPos = p.getPosition();
    sf::Vector2f GhostPos = ghost.getPosition();
    int pacX = PacPos.x / cellSize;
    int pacY = PacPos.y / cellSize;
    int ghostX = GhostPos.x / cellSize;
    int ghostY = GhostPos.y / cellSize;
    if (pacX == ghostX && pacY == ghostY) {
        return true;
    }
    return false;
}

// Alternative method to check if the ghost collides with Pacman based on distance
/*
bool Ghost::checkDeath(Pacman p){
    sf::Vector2f pacPos = p.getPosition();
    sf::Vector2f ghostPos = ghost.getPosition();
    float distance = std::sqrt(std::pow(pacPos.x - ghostPos.x, 2) + std::pow(pacPos.y - ghostPos.y, 2));
    if (distance < cellSize) {
        return true;
    }
    return false;
}
*/

// Getter for change in direction
int Ghost::getChange() const {
    return change;
}

// Getter for cell size
int Ghost::getCellSize() const {
    return cellSize;
}

// Getter for grid size
int Ghost::getGridSize() const {
    return gridSize;
}

// Getter for ghost texture
sf::Texture Ghost::getGhostTexture() const {
    return ghostTexture;
}

// Getter for ghost sprite
sf::Sprite Ghost::getGhost() const {
    return ghost;
}