#ifndef PACMAN_H
#define PACMAN_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entities.h"
#include "Maze.h"

/**
 * @brief Represents the Pacman character in the game.
 */
class Pacman : public Entities {
    private:
        sf::Texture pacmanTexture; ///< Texture for the Pacman sprite
        sf::Texture pacmanfTexture; ///< Texture for the Pacman sprite in a different state
        sf::Sprite pacman; ///< Sprite for the Pacman
        sf::Clock clock; ///< Clock for managing Pacman's movement timing
        sf::Clock clk; ///< Additional clock for managing state changes
        int cellSize; ///< Size of each cell on the game grid
        int gridSize; ///< Size of the game grid
        float speed = 250.0f; ///< Speed of Pacman
        bool boost = false; ///< Flag indicating if Pacman has a speed boost
        bool changed = false; ///< Flag indicating if Pacman's state has changed

    public:
        /**
         * @brief Default constructor for Pacman.
         * Initializes default values for Pacman.
         */
        Pacman();

        /**
         * @brief Constructor for Pacman with parameters.
         * @param window RenderWindow object to draw Pacman on.
         * @param gs Size of the game grid.
         */
        Pacman(sf::RenderWindow& window, int gs);

        /**
         * @brief Draws the Pacman sprite on the game window.
         * @param window RenderWindow object to draw Pacman on.
         */
        void draw(sf::RenderWindow& window) override;

        /**
         * @brief Moves Pacman in the specified direction.
         * @param direction The direction to move Pacman.
         * @param maze The maze in which Pacman moves.
         * @param time The elapsed time used to calculate movement.
         * @return True if the move is successful, false otherwise.
         */
        bool move(int direction, Maze maze, float time) override;

        /**
         * @brief Sets the position of Pacman on the game grid.
         * @param newPos New position of Pacman.
         */
        void setPosition(const sf::Vector2f& newPos) override;

        /**
         * @brief Getter for Pacman's position.
         * @return The position of Pacman on the game grid.
         */
        sf::Vector2f getPosition() const override;

        /**
         * @brief Getter for Pacman's speed.
         * @return The speed of Pacman.
         */
        float getSpeed() const;

        /**
         * @brief Toggles Pacman's speed boost.
         * @param toggle True to increase speed, false to reset speed.
         */
        void increaseSpeed(bool toggle);

        /**
         * @brief Getter for Pacman's texture.
         * @return The texture for the Pacman sprite.
         */
        sf::Texture getPacmanTexture() const;

        /**
         * @brief Getter for Pacman's alternate texture.
         * @return The texture for the Pacman sprite in a different state.
         */
        sf::Texture getPacmanfTexture() const;

        /**
         * @brief Getter for Pacman's sprite.
         * @return The sprite for Pacman.
         */
        sf::Sprite getPacman() const;

        /**
         * @brief Getter for Pacman's clock.
         * @return The clock for managing Pacman's movement timing.
         */
        sf::Clock getClock() const;

        /**
         * @brief Getter for Pacman's additional clock.
         * @return The additional clock for managing state changes.
         */
        sf::Clock getClk() const;

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
         * @brief Getter for boost flag.
         * @return True if Pacman has a speed boost, false otherwise.
         */
        bool getBoost() const;

        /**
         * @brief Getter for changed flag.
         * @return True if Pacman's state has changed, false otherwise.
         */
        bool getChanged() const;
};

#endif