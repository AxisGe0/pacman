#ifndef GHOST_H
#define GHOST_H

#include <SFML/Graphics.hpp>
#include "Entities.h"
#include "Maze.h"
#include "Pacman.h"
#include <iostream>

/**
 * @brief Represents a ghost character in the game.
 */
class Ghost : public Entities {
    private:
        int change = 0; ///< Change in movement direction
        int cellSize; ///< Size of each cell on the game grid
        int gridSize; ///< Size of the game grid
        float speed = 250.0f; ///< Speed of the ghost
        sf::Texture ghostTexture; ///< Texture of the ghost sprite
        sf::Sprite ghost; ///< Sprite for the ghost

    public:
        /**
         * @brief Default constructor for Ghost.
         * Initializes default values for the ghost.
         */
        Ghost();

        /**
         * @brief Constructor for Ghost with parameters.
         * @param window RenderWindow object to draw the ghost on.
         * @param gs Size of the game grid.
         * @param x Initial x position of the ghost.
         * @param y Initial y position of the ghost.
         * @param color Color of the ghost.
         */
        Ghost(sf::RenderWindow& window, int gs, int x, int y, std::string color);

        /**
         * @brief Draws the ghost sprite on the game window.
         * @param window RenderWindow object to draw the ghost on.
         */
        void draw(sf::RenderWindow& window) override;

        /**
         * @brief Moves the ghost in the specified direction.
         * @param direction The direction to move the ghost.
         * @param maze The maze in which the ghost moves.
         * @param time The elapsed time used to calculate movement.
         * @return True if the move is successful, false otherwise.
         */
        bool move(int direction, Maze maze, float time) override;

        /**
         * @brief Sets the position of the ghost on the game grid.
         * @param newPos New position of the ghost.
         */
        void setPosition(const sf::Vector2f& newPos) override;

        /**
         * @brief Getter for the position of the ghost.
         * @return The position of the ghost on the game grid.
         */
        sf::Vector2f getPosition() const override;

        /**
         * @brief Calculates the movement vector for the ghost.
         * @param change Change in movement direction.
         * @param fSpeed Speed factor for the movement.
         * @return The movement vector for the ghost.
         */
        sf::Vector2f getMovement(int change, float fSpeed);

        /**
         * @brief Getter for speed.
         * @return The speed of the ghost.
         */
        float getSpeed() override;

        /**
         * @brief Checks if the ghost collides with the pacman.
         * @param p The pacman object to check collision with.
         * @return True if the ghost collides with the pacman, false otherwise.
         */
        bool checkDeath(Pacman p);

        /**
         * @brief Getter for change.
         * @return The change in movement direction.
         */
        int getChange() const;

        /**
         * @brief Getter for cellSize.
         * @return The size of each cell on the game grid.
         */
        int getCellSize() const;

        /**
         * @brief Getter for gridSize.
         * @return The size of the game grid.
         */
        int getGridSize() const;

        /**
         * @brief Getter for ghostTexture.
         * @return The texture of the ghost sprite.
         */
        sf::Texture getGhostTexture() const;

        /**
         * @brief Getter for ghost sprite.
         * @return The sprite of the ghost.
         */
        sf::Sprite getGhost() const;
};

#endif