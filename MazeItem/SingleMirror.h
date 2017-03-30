#ifndef ENGG1111_ASSIGNMENT1_SINGLEMIRROR_H
#define ENGG1111_ASSIGNMENT1_SINGLEMIRROR_H

#include "../MazeItem.h"
#include "../Utility.h"

class SingleMirror : public MazeItem
{
public:
    SingleMirror(const Position &position, MirrorDirection mirrorDirection) :
            MazeItem(position, MazeItemType::SingleMirror)
            , mirrorDirection(mirrorDirection)
    {
    }

    const MirrorDirection getMirrorDirection() const
    {
        return mirrorDirection;
    }

    std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) override
    {
        LaserDirection nextLaserDirection;
        Position nextPos = this->getPosition();

        if (MirrorDirection::NorthWest == this->getMirrorDirection())
        {
            switch (laserDirection)
            {
                case LaserDirection::East:
                {
                    auto result = Utility::bendLaserLeft(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                case LaserDirection::South:
                {
                    auto result = Utility::bendLaserRight(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                default:
                    break;
            }
        }
        else if (MirrorDirection::SouthEast == this->getMirrorDirection())
        {
            switch (laserDirection)
            {
                case LaserDirection::West:
                {
                    auto result = Utility::bendLaserLeft(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                case LaserDirection::North:
                {
                    auto result = Utility::bendLaserRight(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                default:
                    break;
            }
        }
        else if (MirrorDirection::SouthWest == this->getMirrorDirection())
        {
            switch (laserDirection)
            {
                case LaserDirection::East:
                {
                    auto result = Utility::bendLaserRight(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                case LaserDirection::North:
                {
                    auto result = Utility::bendLaserLeft(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                default:
                    break;
            }
        }
        else if (MirrorDirection::NorthEast == this->getMirrorDirection())
        {
            switch (laserDirection)
            {
                case LaserDirection::West:
                {
                    auto result = Utility::bendLaserRight(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                case LaserDirection::South:
                {
                    auto result = Utility::bendLaserLeft(laserDirection, this->getPosition());
                    return std::make_tuple(false, std::get<1>(result), std::get<0>(result));
                }
                default:
                    break;
            }
        }

        return {true, this->getPosition(), laserDirection};
    }

private:
    const MirrorDirection mirrorDirection;
};

#endif //ENGG1111_ASSIGNMENT1_SINGLEMIRROR_H
