#include "Entities.h"

// Default constructor for Entities
Entities::Entities() {}

// Moves the entity in the specified direction, returns false by default
bool Entities::move(int direction, Maze maze, float time) {
    return false; // Default implementation returns false
}

// Getter for the speed of the entity
float Entities::getSpeed() {
    return speed; // Return the current speed
}
