#ifndef SPEEDDOT_H
#define SPEEDDOT_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Collectables.h"
#include "Pacman.h"

/**
 * @brief Class representing the SpeedDot collectable in the game.
 * Inherits from the Collectables base class.
 */
class SpeedDot : public Collectables {
    private:
        int gridSize; ///< Size of the game grid
        int cellSize; ///< Size of each cell in the grid
        int points = 50; ///< Points awarded for collecting the SpeedDot
        int n = 3; ///< Number of SpeedDots to be placed
        int **maze; ///< Pointer to a 2D array representing the game maze
        float scaleFactor = 1.0f; ///< Scale factor for rendering the SpeedDot
        bool isScalingDown = false; ///< Flag indicating if the SpeedDot is scaling down
        sf::Clock animationClock; ///< Clock for handling animations

    public:
        /**
         * @brief Default constructor for SpeedDot.
         */
        SpeedDot();

        /**
         * @brief Parameterized constructor for SpeedDot.
         * @param gs Grid size
         * @param width Width of the game window
         * @param mz Pointer to the 2D array representing the game maze
         */
        SpeedDot(int gs, int width, int **mz);

        /**
         * @brief Places the SpeedDot randomly in the maze.
         */
        void placeRandomly();

        /**
         * @brief Draws the SpeedDot on the game window.
         * @param window The SFML window to draw on
         */
        void draw(sf::RenderWindow& window) override;

        /**
         * @brief Calculates the points earned by the pacman for collecting the SpeedDot.
         * @param pacman The pacman object to calculate points for
         * @return The points earned by the pacman
         */
        int addPoints(Pacman &pacman);

        /**
         * @brief Getter for gridSize.
         * @return The size of the game grid
         */
        int getGridSize() const;

        /**
         * @brief Getter for cellSize.
         * @return The size of each cell in the grid
         */
        int getCellSize() const;

        /**
         * @brief Getter for points.
         * @return The points awarded for collecting the SpeedDot
         */
        int getPoints() const;

        /**
         * @brief Getter for n.
         * @return The value of n
         */
        int getN() const;

        /**
         * @brief Getter for maze.
         * @return Pointer to the 2D array representing the game maze
         */
        int** getMaze() const;

        /**
         * @brief Getter for scaleFactor.
         * @return The scale factor for rendering the SpeedDot
         */
        float getScaleFactor() const;

        /**
         * @brief Getter for isScalingDown.
         * @return The flag indicating if the SpeedDot is scaling down
         */
        bool getIsScalingDown() const;

        /**
         * @brief Getter for animationClock.
         * @return The clock for handling animations
         */
        sf::Clock getAnimationClock() const;
};

#endif // SPEEDDOT_H
