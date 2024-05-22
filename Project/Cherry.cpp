#include "Cherry.h"

// Default constructor for Cherry
Cherry::Cherry() {}

 // Constructor for Cherry with parameters
Cherry::Cherry(int gs, int width, int **mz) : gridSize(gs), cellSize(width / gridSize), maze(mz) {
    // Load cherry texture from file
    if (!cherryTexture.loadFromFile("images/cherry.png")) {
        std::cerr << "Error: Failed to load cherry texture file." << std::endl;
    } else {
        placeRandomly(); // Place cherry randomly on the maze
    }
}

// Draws the cherry on the game window
void Cherry::draw(sf::RenderWindow& window) {
    sf::RectangleShape cherry(sf::Vector2f(cellSize, cellSize));
    cherry.setFillColor(sf::Color::White);
    cherry.setTexture(&cherryTexture);
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 3) { // Check if the cell has a cherry
                cherry.setPosition(x * cellSize, y * cellSize);
                window.draw(cherry); // Draw the cherry
            }
        }
    }
}

// Calculates and returns points if Pacman collects the cherry
int Cherry::addPoints(Pacman pacman) {
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / cellSize;
    int Y = pos.y / cellSize;
    if (maze[Y][X] == 3) { // Check if Pacman is on a cherry cell
        maze[Y][X] = 8; // Mark the cell as empty
        placeRandomly(); // Place a new cherry randomly
        return points; // Return the points awarded for collecting the cherry
    }
    return 0;
}

// Places the cherry randomly on the maze
void Cherry::placeRandomly() {
    int count = 0;
    while (count < n) {
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        if (maze[x][y] == 0 || maze[x][y] == 8) { // Check if the cell is empty or previously had a cherry
            maze[x][y] = 3; // Place the cherry
            count++;
        }
    }
}

// Getter for gridSize
int Cherry::getGridSize() const {
    return gridSize;
}

// Getter for cellSize
int Cherry::getCellSize() const {
    return cellSize;
}

// Getter for points
int Cherry::getPoints() const {
    return points;
}

// Getter for n
int Cherry::getN() const {
    return n;
}

// Getter for maze
int** Cherry::getMaze() const {
    return maze;
}

// Getter for cherryTexture
sf::Texture Cherry::getCherryTexture() const {
    return cherryTexture;
}