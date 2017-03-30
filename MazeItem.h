#ifndef ENGG1111_ASSIGNMENT1_MAZEITEM_H
#define ENGG1111_ASSIGNMENT1_MAZEITEM_H

#include <tuple>

#include "Position.h"
#include "Common.h"

class MazeItem
{
public:
    MazeItem(const Position &position, MazeItemType type) :
            position(position)
            , type(type)
    {
    }

    MazeItem(const MazeItem &rhs) :
            position(rhs.position)
            , type(rhs.type)
    {
    }

    virtual ~MazeItem()
    {
    }

    const Position& getPosition() const
    {
        return position;
    }

    MazeItemType getType() const
    {
        return type;
    }

    // return {isFinish, nextPos, nextLaserDirection}
    virtual std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) = 0;

private:
    const Position position;
    MazeItemType type;
};

#endif //ENGG1111_ASSIGNMENT1_MAZEITEM_H
