#ifndef ENGG1111_ASSIGNMENT1_LASERSOURCE_H
#define ENGG1111_ASSIGNMENT1_LASERSOURCE_H

#include "../MazeItem.h"

class LaserSource : public MazeItem
{
public:
    LaserSource(const Position &position, LaserDirection laserDirection, unsigned int id) :
            MazeItem(position, MazeItemType::LaserSource)
            , laserDirection(laserDirection)
            , id(id)
    {
    }

    const LaserDirection getLaserDirection() const
    {
        return laserDirection;
    }

    std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) override
    {
        return std::make_tuple(true, this->getPosition(), laserDirection);
    }

    unsigned int getId() const
    {
        return id;
    }

    const Position startLaser() const
    {
        Position nextPos = this->getPosition();

        switch (this->getLaserDirection())
        {
            case LaserDirection::East:
                ++nextPos.x;
                break;
            case LaserDirection::West:
                --nextPos.x;
                break;
            case LaserDirection::North:
                ++nextPos.y;
                break;
            case LaserDirection::South:
                --nextPos.y;
                break;
        }

        return nextPos;
    }

private:
    const LaserDirection laserDirection;
    unsigned int id;
};

#endif //ENGG1111_ASSIGNMENT1_LASERSOURCE_H
