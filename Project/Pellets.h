#ifndef PELLETS_H
#define PELLETS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collectables.h"
#include "Pacman.h"

/**
 * @brief Class representing the Pellets collectable in the game.
 * Inherits from the Collectables base class.
 */
class Pellets : public Collectables {
    private:
        int gridSize; ///< Size of the game grid
        int cellSize; ///< Size of each cell in the grid
        int points = 10; ///< Points awarded for collecting the Pellet
        int **maze; ///< Pointer to a 2D array representing the game maze
        sf::SoundBuffer buffer; ///< Sound buffer for the Pellet collection sound
        sf::Sound sound; ///< Sound for the Pellet collection

    public:
        /**
         * @brief Default constructor for Pellets.
         */
        Pellets();

        /**
         * @brief Parameterized constructor for Pellets.
         * @param gs Grid size
         * @param width Width of the game window
         * @param mz Pointer to the 2D array representing the game maze
         */
        Pellets(int gs, int width, int **mz);

        /**
         * @brief Draws the Pellets on the game window.
         * @param window The SFML window to draw on
         */
        void draw(sf::RenderWindow& window) override;

        /**
         * @brief Calculates the points earned by the pacman for collecting the Pellets.
         * @param pacman The pacman object to calculate points for
         * @return The points earned by the pacman
         */
        int addPoints(Pacman pacman) override;

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
         * @return The points awarded for collecting the Pellets
         */
        int getPoints() const;

        /**
         * @brief Getter for maze.
         * @return Pointer to the 2D array representing the game maze
         */
        int** getMaze() const;

        /**
         * @brief Getter for buffer.
         * @return The sound buffer for the Pellet collection sound
         */
        sf::SoundBuffer getBuffer() const;

        /**
         * @brief Getter for sound.
         * @return The sound for the Pellet collection
         */
        sf::Sound getSound() const;
};

#endif // PELLETS_H
