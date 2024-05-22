#ifndef ENTITIES_H
#define ENTITIES_H

#include "Elements.h"
#include "Maze.h"

/**
 * @brief Base class representing entities in the game.
 */
class Entities : public Elements {
    private:
        int speed; ///< Speed of the entity

    public:
        /**
         * @brief Default constructor for Entities.
         * Sets the default value for speed.
         */
        Entities();

        /**
         * @brief Moves the entity in the specified direction.
         * @param direction The direction to move the entity.
         * @param maze The maze in which the entity moves.
         * @param time The elapsed time used to calculate movement.
         * @return True if the move is successful, false otherwise.
         */
        virtual bool move(int direction, Maze maze, float time);

        /**
         * @brief Getter for speed.
         * @return The speed of the entity.
         */
        virtual float getSpeed();
};

#endif