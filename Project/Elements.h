#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <SFML/Graphics.hpp>

/**
 * @brief Base class representing elements in the game.
 */
class Elements {
    private:
        sf::Vector2f position; ///< Position of the element on the game grid

    public:
        /**
         * @brief Default constructor for Elements.
         * Initializes the position to (0, 0).
         */
        Elements();

        /**
         * @brief Pure virtual function to draw the element on the game window.
         * @param window RenderWindow object to draw the element on.
         */
        virtual void draw(sf::RenderWindow& window) = 0;

        /**
         * @brief Sets the position of the element on the game grid.
         * @param newPos New position of the element.
         */
        virtual void setPosition(const sf::Vector2f& newPos);

        /**
         * @brief Getter for position.
         * @return The position of the element on the game grid.
         */
        virtual sf::Vector2f getPosition() const;
};

#endif