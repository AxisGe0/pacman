#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include "Elements.h"

/**
 * @brief Represents the game maze.
 */
class Maze : public Elements {
    private:
        int gridSize; ///< Size of the game grid
        int cellSize; ///< Size of each cell on the game grid
        int **maze; ///< 2D array representing the maze layout
        sf::Texture right_corner; ///< Texture for the right corner of the maze
        sf::Texture left_corner; ///< Texture for the left corner of the maze
        sf::Texture b_right_corner; ///< Texture for the bottom right corner of the maze
        sf::Texture b_left_corner; ///< Texture for the bottom left corner of the maze
        sf::Texture top_line; ///< Texture for the top line of the maze
        sf::Texture left_line; ///< Texture for the left line of the maze

    public:
        /**
         * @brief Default constructor for Maze.
         * Initializes default values for the maze.
         */
        Maze();

        /**
         * @brief Constructor for Maze with parameters.
         * @param gs Size of the game grid.
         * @param width Width of the game window.
         */
        Maze(int gs, int width);

        /**
         * @brief Draws the maze on the game window.
         * @param window RenderWindow object to draw the maze on.
         */
        void draw(sf::RenderWindow& window) override;

        /**
         * @brief Resets the maze to the initial state.
         */
        void reset();

        /**
         * @brief Checks if a given cell is a wall.
         * @param x X-coordinate of the cell.
         * @param y Y-coordinate of the cell.
         * @return True if the cell is a wall, false otherwise.
         */
        bool isWall(int x, int y);

        /**
         * @brief Sets up the initial maze layout.
         */
        void setupMaze();

        /**
         * @brief Getter for the maze layout.
         * @return Pointer to the 2D array representing the maze layout.
         */
        int **getMaze();

        /**
         * @brief Getter for gridSize.
         * @return The size of the game grid.
         */
        int getGridSize() const;

        /**
         * @brief Getter for cellSize.
         * @return The size of each cell on the game grid.
         */
        int getCellSize() const;

        /**
         * @brief Getter for right corner texture.
         * @return The texture for the right corner of the maze.
         */
        sf::Texture getRightCorner() const;

        /**
         * @brief Getter for left corner texture.
         * @return The texture for the left corner of the maze.
         */
        sf::Texture getLeftCorner() const;

        /**
         * @brief Getter for bottom right corner texture.
         * @return The texture for the bottom right corner of the maze.
         */
        sf::Texture getBottomRightCorner() const;

        /**
         * @brief Getter for bottom left corner texture.
         * @return The texture for the bottom left corner of the maze.
         */
        sf::Texture getBottomLeftCorner() const;

        /**
         * @brief Getter for top line texture.
         * @return The texture for the top line of the maze.
         */
        sf::Texture getTopLine() const;

        /**
         * @brief Getter for left line texture.
         * @return The texture for the left line of the maze.
         */
        sf::Texture getLeftLine() const;
};

#endif