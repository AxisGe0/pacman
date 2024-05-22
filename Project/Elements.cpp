#include "Elements.h"

// Default constructor for Elements
Elements::Elements() {}

// Sets the position of the element
void Elements::setPosition(const sf::Vector2f& newPos) {
    position = newPos; // Update the position to the new position
}

// Getter for the position of the element
sf::Vector2f Elements::getPosition() const {
    return position; // Return the current position
}