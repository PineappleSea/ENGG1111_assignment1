#ifndef ENGG1111_ASSIGNMENT1_DESTINATION_H
#define ENGG1111_ASSIGNMENT1_DESTINATION_H

#include "../MazeItem.h"

class Destination : public MazeItem
{
public:
    Destination(const Position &position, unsigned int id) :
            MazeItem(position, MazeItemType::Destination)
            , id(id)
    {
    }

    std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) override
    {
        return {true, this->getPosition(), laserDirection};
    }

    unsigned int getId() const
    {
        return id;
    }

private:
    unsigned int id;
};

#endif //ENGG1111_ASSIGNMENT1_DESTINATION_H
