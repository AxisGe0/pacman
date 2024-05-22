#include "Collectables.h"

// Default constructor for Collectables
Collectables::Collectables() {}

// Virtual function to add points, returns 0 by default
int Collectables::addPoints(Pacman pacman) {
    return 0;
}

// Getter for points
int Collectables::getPoints() const {
    return points;
}
