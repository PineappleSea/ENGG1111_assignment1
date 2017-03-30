#ifndef ENGG1111_ASSIGNMENT1_EMPTYITEM_H
#define ENGG1111_ASSIGNMENT1_EMPTYITEM_H

#include "../MazeItem.h"

class EmptyItem : public MazeItem
{
public:
    EmptyItem(const Position &position) :
            MazeItem(position, MazeItemType::Empty)
    {
    }

    std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) override
    {
        Position nextPos = this->getPosition();

        switch (laserDirection)
        {
            case LaserDirection::East:
                ++nextPos.x;
                break;
            case LaserDirection ::West:
                --nextPos.x;
                break;
            case LaserDirection ::North:
                ++nextPos.y;
                break;
            case LaserDirection ::South:
                --nextPos.y;
                break;
        }

        return {false, nextPos, laserDirection};
    }
};

#endif //ENGG1111_ASSIGNMENT1_EMPTYITEM_H
