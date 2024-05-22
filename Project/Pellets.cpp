#include "Pellets.h"

// Default constructor for Pellets
Pellets::Pellets() {}

// Constructor for Pellets with parameters
Pellets::Pellets(int gs, int width, int **mz) : gridSize(gs), cellSize(width / gridSize), maze(mz) {
    // Load sound buffer and set sound for eating pellets
    buffer.loadFromFile("sounds/sound_eating.mp3");
    sound.setBuffer(buffer);
}

// Draws the pellets on the game window
void Pellets::draw(sf::RenderWindow& window) {
    sf::CircleShape dot(cellSize / 12);
    dot.setFillColor(sf::Color::White);
    float offset = (cellSize - dot.getRadius() * 2) / 2;
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 0) { // Check if the cell contains a pellet
                dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                window.draw(dot); // Draw the pellet
            }
        }
    }
}

// Calculates and returns points if Pacman collects a pellet
int Pellets::addPoints(Pacman pacman) {
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / cellSize;
    int Y = pos.y / cellSize;
    if (maze[Y][X] == 0) { // Check if Pacman is on a pellet cell
        maze[Y][X] = 8; // Mark the cell as empty
        if (sound.getStatus() != sf::Sound::Status::Playing) {
            sound.play(); // Play eating sound
        }
        return points; // Return the points awarded for collecting the pellet
    }
    return 0;
}

// Getter for gridSize
int Pellets::getGridSize() const {
    return gridSize;
}

// Getter for cellSize
int Pellets::getCellSize() const {
    return cellSize;
}

// Getter for points
int Pellets::getPoints() const {
    return points;
}

// Getter for maze
int** Pellets::getMaze() const {
    return maze;
}

// Getter for sound buffer
sf::SoundBuffer Pellets::getBuffer() const {
    return buffer;
}

// Getter for sound
sf::Sound Pellets::getSound() const {
    return sound;
}