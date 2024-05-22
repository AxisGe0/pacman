#ifndef COLLECTABLES_H
#define COLLECTABLES_H

#include "Elements.h"
#include "Pacman.h"

/**
 * @brief Base class representing collectable items in the game.
 */
class Collectables : public Elements {
    private:
        int points; ///< Points awarded for collecting the item

    public:
        /**
         * @brief Default constructor for Collectables.
         * Sets the default value for points.
         */
        Collectables();

        /**
         * @brief Virtual function to calculate the points earned by the pacman.
         * @param pacman The pacman object to calculate points for.
         * @return The points earned by the pacman.
         */
        virtual int addPoints(Pacman pacman);

        /**
         * @brief Getter for points.
         * @return The points awarded for collecting the item.
         */
        int getPoints() const;
};

#endif