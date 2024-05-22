#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <fstream>
#include <string>
#include "Maze.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Pellets.h"
#include "SpeedDot.h"
#include "Cherry.h"

/**
 * @brief Main class representing the game.
 */
class Game {
    private:
        sf::RenderWindow window; ///< The game window
        sf::Font font; ///< Font used for text in the game
        sf::Text score; ///< Text displaying the score
        sf::Text livesText; ///< Text displaying the number of lives
        sf::Text title; ///< Text displaying the game title
        sf::Text playText; ///< Text displaying the play button
        sf::Text highScoreText; ///< Text displaying the high score
        sf::SoundBuffer buffer, buffer_ready, buffer_die; ///< Sound buffers for various game sounds
        sf::Sound siren, sound_ready, sound_die; ///< Sound objects for various game sounds
        sf::Clock clock, clock_die; ///< Clocks for timing events
        int width, height; ///< Dimensions of the game window
        int highScore = 0; ///< The high score of the game
        int points = 0; ///< The current score of the player
        int lives = 3; ///< The number of lives the player has
        int direction = 0; ///< Direction of movement (0 left, 1 right, 2 up, 3 down, 4 none)
        bool isAlive = false; ///< Flag indicating if the player is alive
        bool canGameStart = false; ///< Flag indicating if the game can start
        bool isDying = false; ///< Flag indicating if the player is dying
        Maze maze; ///< The game maze
        Pacman player; ///< The player character
        Ghost* ghosts[4]; ///< Array of ghost characters
        Pellets pellets; ///< Pellets in the game
        SpeedDot speedDot; ///< SpeedDot in the game
        Cherry cherry; ///< Cherry in the game

    public:
        /**
         * @brief Constructor for Game.
         * @param h Height of the game window.
         * @param w Width of the game window.
         */
        Game(int h, int w);

        /**
         * @brief Runs the game loop.
         */
        void run();

        /**
         * @brief Handles keyboard inputs.
         */
        void handleKeys();

        /**
         * @brief Handles mouse clicks.
         */
        void handleClicks();

        /**
         * @brief Renders the game window.
         */
        void render();

        /**
         * @brief Resets the game to the initial state.
         */
        void resetGame();

        /**
         * @brief Getter for font.
         * @return The font used for text in the game.
         */
        sf::Font getFont();

        /**
         * @brief Getter for score text.
         * @return The text displaying the score.
         */
        sf::Text getScore();

        /**
         * @brief Getter for lives text.
         * @return The text displaying the number of lives.
         */
        sf::Text getLivesText();

        /**
         * @brief Getter for title text.
         * @return The text displaying the game title.
         */
        sf::Text getTitle();

        /**
         * @brief Getter for play text.
         * @return The text displaying the play button.
         */
        sf::Text getPlayText();

        /**
         * @brief Getter for high score text.
         * @return The text displaying the high score.
         */
        sf::Text getHighScoreText();

        /**
         * @brief Getter for window width.
         * @return The width of the game window.
         */
        int getWidth();

        /**
         * @brief Getter for window height.
         * @return The height of the game window.
         */
        int getHeight();

        /**
         * @brief Getter for high score.
         * @return The high score of the game.
         */
        int getHighScore();

        /**
         * @brief Getter for points.
         * @return The current score of the player.
         */
        int getPoints();

        /**
         * @brief Getter for lives.
         * @return The number of lives the player has.
         */
        int getLives();

        /**
         * @brief Getter for direction.
         * @return The direction of movement.
         */
        int getDirection();

        /**
         * @brief Getter for isAlive flag.
         * @return True if the player is alive, false otherwise.
         */
        bool getIsAlive();

        /**
         * @brief Getter for canGameStart flag.
         * @return True if the game can start, false otherwise.
         */
        bool getCanGameStart();

        /**
         * @brief Getter for isDying flag.
         * @return True if the player is dying, false otherwise.
         */
        bool getIsDying();

        /**
         * @brief Destructor for Game.
         */
        ~Game();
};

#endif