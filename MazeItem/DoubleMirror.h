#ifndef ENGG1111_ASSIGNMENT1_DOUBLEMIRROR_H
#define ENGG1111_ASSIGNMENT1_DOUBLEMIRROR_H

#include "../MazeItem.h"
#include "../Utility.h"

class DoubleMirror : public MazeItem
{
public:
    DoubleMirror(const Position &position, MirrorDirection mirrorDirection) :
            MazeItem(position, MazeItemType::DoubleMirror)
            , mirrorDirection(mirrorDirection)
    {
    }

    const MirrorDirection getMirrorDirection() const
    {
        return mirrorDirection;
    }

    std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) override
    {
        if (MirrorDirection::NorthWest == this->getMirrorDirection() || MirrorDirection::SouthEast == this->getMirrorDirection())
        {
            switch (laserDirection)
            {
                case LaserDirection::East:
                case LaserDirection::West:
                {
                    auto result = Utility::bendLaserLeft(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                case LaserDirection::South:
                case LaserDirection::North:
                {
                    auto result = Utility::bendLaserRight(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
            }
        }
        else // if (MirrorDirection::NorthEast == this->getMirrorDirection() || MirrorDirection::SouthWest == this->getMirrorDirection())
        {
            switch (laserDirection)
            {
                case LaserDirection::East:
                case LaserDirection::West:
                {
                    auto result = Utility::bendLaserRight(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                case LaserDirection::South:
                case LaserDirection::North:
                {
                    auto result = Utility::bendLaserLeft(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
            }
        }
    }

private:
    const MirrorDirection mirrorDirection;
};

#endif //ENGG1111_ASSIGNMENT1_DOUBLEMIRROR_H
