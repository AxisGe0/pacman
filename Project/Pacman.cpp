#include "Pacman.h"

// Default constructor for Pacman
Pacman::Pacman() {}

// Constructor for Pacman with parameters
Pacman::Pacman(sf::RenderWindow& window, int gs) : gridSize(gs) {
    cellSize = window.getSize().x / gridSize;
    if (!pacmanTexture.loadFromFile("images/pacman.png") || !pacmanfTexture.loadFromFile("images/pacman-full.png")) {
        std::cerr << "Error: Failed to load one or more pacman texture files." << std::endl;
    } else {
        // Set Pacman texture, origin, position, and scale
        pacman.setTexture(pacmanTexture);
        pacman.setOrigin(pacmanTexture.getSize().x / 2, pacmanTexture.getSize().y / 2);
        pacman.setPosition(window.getSize().x / 2, window.getSize().y / 2);
        pacman.setScale(cellSize / pacman.getLocalBounds().width, cellSize / pacman.getLocalBounds().height);
    }
}

// Draws the Pacman on the game window
void Pacman::draw(sf::RenderWindow& window) {
    // Change texture every 0.2 seconds
    if(clk.getElapsedTime().asSeconds() > 0.2f) {
        changed = !changed;
        pacman.setTexture(changed ? pacmanfTexture : pacmanTexture);
        clk.restart();
    } 
    window.draw(pacman);
}

// Moves Pacman in the specified direction
bool Pacman::move(int direction, Maze maze, float time) {
    sf::Vector2f movement(0.0f, 0.0f);
    float fSpeed = time * speed * (boost ? 2.0f : 1.0f);
    // Set movement direction and Pacman rotation based on input direction
    if (direction == 0) {
        movement.x = -fSpeed;
        pacman.setRotation(180.0f);
    } else if (direction == 1) {
        movement.x = fSpeed;
        pacman.setRotation(0.0f);
    } else if (direction == 2) {
        movement.y = -fSpeed;
        pacman.setRotation(-90.0f);
    } else if (direction == 3) {
        movement.y = fSpeed;
        pacman.setRotation(90.0f);
    }
    sf::Vector2f newPos = pacman.getPosition() + movement;
    int X = newPos.x / cellSize;
    int Y = newPos.y / cellSize;
    sf::Vector2f pos(newPos.x, newPos.y);
    // Check if the new position is not a wall
    if (!maze.isWall(X, Y)) {
        if (direction == 0 || direction == 1) {
            pos = sf::Vector2f(newPos.x, Y * cellSize + (cellSize / 2));
        } else if (direction == 2 || direction == 3) {
            pos = sf::Vector2f(X * cellSize + (cellSize / 2), newPos.y);
        } else {
            pos = sf::Vector2f(X * cellSize + (cellSize / 2), Y * cellSize + (cellSize / 2));
        }
        pacman.setPosition(pos);
    } else {
        return false;
    }
    return true;
}

// Sets the position of Pacman
void Pacman::setPosition(const sf::Vector2f& newPos) {
    pacman.setPosition(newPos);
}

// Getter for Pacman's position
sf::Vector2f Pacman::getPosition() const {
    return pacman.getPosition();
}

// Getter for Pacman's speed
float Pacman::getSpeed() const {
    return speed;
}

// Toggles Pacman's speed boost
void Pacman::increaseSpeed(bool toggle) {
    if (toggle) {
        clock.restart();
        boost = true;
    } else if (boost) {
        float seconds = clock.getElapsedTime().asSeconds();
        if (seconds > 5) {
            boost = false;
        }
    }
}

// Getter for Pacman's texture
sf::Texture Pacman::getPacmanTexture() const {
    return pacmanTexture;
}

// Getter for Pacman's alternate texture
sf::Texture Pacman::getPacmanfTexture() const {
    return pacmanfTexture;
}

// Getter for Pacman's sprite
sf::Sprite Pacman::getPacman() const {
    return pacman;
}

// Getter for Pacman's clock
sf::Clock Pacman::getClock() const {
    return clock;
}

// Getter for Pacman's additional clock
sf::Clock Pacman::getClk() const {
    return clk;
}

// Getter for cell size
int Pacman::getCellSize() const {
    return cellSize;
}

// Getter for grid size
int Pacman::getGridSize() const {
    return gridSize;
}

// Getter for boost flag
bool Pacman::getBoost() const {
    return boost;
}

// Getter for changed flag
bool Pacman::getChanged() const {
    return changed;
}