#include "SpeedDot.h"

// Default constructor for SpeedDot
SpeedDot::SpeedDot() {}

// Constructor for SpeedDot with parameters
SpeedDot::SpeedDot(int gs, int width, int **mz) : gridSize(gs), cellSize(width / gridSize), maze(mz) {
    placeRandomly(); // Place SpeedDot randomly on the maze
}

// Places the SpeedDot randomly on the maze
void SpeedDot::placeRandomly() {
    int count = 0;
    while (count < n) {
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        if (maze[x][y] == 0) { // Check if the cell is empty
            maze[x][y] = 2; // Place SpeedDot
            count++;
        }
    }
}

// Draws the SpeedDot on the game window
void SpeedDot::draw(sf::RenderWindow& window) {
    sf::CircleShape dot((cellSize / 3) * scaleFactor);
    dot.setFillColor(sf::Color::White);
    float offset = (cellSize - dot.getRadius() * 2) / 2;
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            if (maze[y][x] == 2) { // Check if the cell contains a SpeedDot
                dot.setPosition(x * cellSize + offset, y * cellSize + offset);
                window.draw(dot); // Draw the SpeedDot
            }
        }
    }
    // Animate the scaling of the SpeedDot
    if (animationClock.getElapsedTime().asMilliseconds() > 10) {
        if (isScalingDown) {
            scaleFactor -= 0.01f;
            if (scaleFactor <= 0.5f) {
                isScalingDown = false;
            }
        } else {
            scaleFactor += 0.01f;
            if (scaleFactor >= 1.0f) {
                isScalingDown = true; 
            }
        }
        animationClock.restart();
    }
}

// Calculates and returns points if Pacman collects the SpeedDot
int SpeedDot::addPoints(Pacman &pacman) {
    sf::Vector2f pos = pacman.getPosition();
    int X = pos.x / cellSize;
    int Y = pos.y / cellSize;
    pacman.increaseSpeed(false); // Ensure Pacman's speed boost status is updated
    if (maze[Y][X] == 2) { // Check if Pacman is on a SpeedDot cell
        maze[Y][X] = 8; // Mark the cell as empty
        pacman.increaseSpeed(true); // Increase Pacman's speed
        return points; // Return the points awarded for collecting the SpeedDot
    }
    return 0;
}

// Getter for gridSize
int SpeedDot::getGridSize() const {
    return gridSize;
}

// Getter for cellSize
int SpeedDot::getCellSize() const {
    return cellSize;
}

// Getter for points
int SpeedDot::getPoints() const {
    return points;
}

// Getter for n
int SpeedDot::getN() const {
    return n;
}

// Getter for maze
int** SpeedDot::getMaze() const {
    return maze;
}

// Getter for scaleFactor
float SpeedDot::getScaleFactor() const {
    return scaleFactor;
}

// Getter for isScalingDown flag
bool SpeedDot::getIsScalingDown() const {
    return isScalingDown;
}

// Getter for animationClock
sf::Clock SpeedDot::getAnimationClock() const {
    return animationClock;
}
