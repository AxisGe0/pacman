#ifndef CHERRY_H
#define CHERRY_H

#include <iostream>
#include "Collectables.h"
#include "Pacman.h"

/**
 * @brief Represents a cherry collectable item in the game.
 */
class Cherry : public Collectables {
    private:
        int gridSize;    ///< Size of the game grid
        int cellSize;    ///< Size of each cell on the grid
        int points = 100;///< Points awarded for collecting the cherry
        int n = 1;       ///< Number of cherries to be placed
        int **maze;      ///< Pointer to the game maze
        sf::Texture cherryTexture; ///< Texture of the cherry sprite

    public:
        /**
         * @brief Default constructor for Cherry.
         * Sets the default values for gridSize, cellSize, and maze.
         */
        Cherry();

        /**
         * @brief Constructor for Cherry.
         * @param gs Size of the game grid.
         * @param width Width of the game window.
         * @param mz Pointer to the game maze.
         */
        Cherry(int gs, int width, int **mz);

        /**
         * @brief Draws the cherry sprite on the game window.
         * @param window RenderWindow object to draw the cherry on.
         */
        void draw(sf::RenderWindow& window) override;

        /**
         * @brief Calculates the points earned by the pacman.
         * @param pacman The pacman object to calculate points for.
         * @return The points earned by the pacman.
         */
        int addPoints(Pacman pacman) override;

        /**
         * @brief Places the cherry randomly on the game grid.
         */
        void placeRandomly();

        /**
         * @brief Getter for gridSize.
         * @return The size of the game grid.
         */
        int getGridSize() const;

        /**
         * @brief Getter for cellSize.
         * @return The size of each cell on the grid.
         */
        int getCellSize() const;

        /**
         * @brief Getter for points.
         * @return The points awarded for collecting the cherry.
         */
        int getPoints() const;

        /**
         * @brief Getter for n.
         * @return The number of cherries to be placed.
         */
        int getN() const;

        /**
         * @brief Getter for maze.
         * @return Pointer to the game maze.
         */
        int** getMaze() const;

        /**
         * @brief Getter for cherryTexture.
         * @return The texture of the cherry sprite.
         */
        sf::Texture getCherryTexture() const;
};

#endif