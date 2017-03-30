#ifndef ENGG1111_ASSIGNMENT1_UTILITY_H
#define ENGG1111_ASSIGNMENT1_UTILITY_H

#include <tuple>
#include <string>
#include <iostream>

#include "Common.h"
#include "Position.h"

class Utility
{
public:
    static std::tuple<LaserDirection, Position> bendLaserLeft(LaserDirection currLaserDirectiion, const Position &currPos)
    {
        Position nextPos = currPos;
        LaserDirection nextLaserDirection;

        switch (currLaserDirectiion)
        {
            case LaserDirection::East:
                nextLaserDirection = LaserDirection::North;
                ++nextPos.y;
                break;
            case LaserDirection::South:
                nextLaserDirection = LaserDirection::East;
                ++nextPos.x;
                break;
            case LaserDirection::West:
                nextLaserDirection = LaserDirection::South;
                --nextPos.y;
                break;
            case LaserDirection::North:
                nextLaserDirection = LaserDirection::West;
                --nextPos.x;
                break;
        }

        return std::make_tuple(nextLaserDirection, nextPos);
    }

    static std::tuple<LaserDirection, Position> bendLaserRight(LaserDirection currLaserDirectiion, const Position &currPos)
    {
        Position nextPos = currPos;
        LaserDirection nextLaserDirection;

        switch (currLaserDirectiion)
        {
            case LaserDirection::East:
                nextLaserDirection = LaserDirection::South;
                --nextPos.y;
                break;
            case LaserDirection::South:
                nextLaserDirection = LaserDirection::West;
                --nextPos.x;
                break;
            case LaserDirection::West:
                nextLaserDirection = LaserDirection::North;
                ++nextPos.y;
                break;
            case LaserDirection::North:
                nextLaserDirection = LaserDirection::East;
                ++nextPos.x;
                break;
        }

        return std::make_tuple(nextLaserDirection, nextPos);
    }

    static MazeItemType itemStrToEnum(const std::string &value)
    {
        if ("source" == value)
            return MazeItemType::LaserSource;
        else if ("dest" == value)
            return MazeItemType::Destination;
        else if ("single" == value)
            return MazeItemType::SingleMirror;
        else if ("double" == value)
            return MazeItemType::DoubleMirror;
        else if ("block" == value)
            return MazeItemType::Block;
        else
            return MazeItemType::Empty;
    }

    static LaserDirection laserDirectionStrToEnum(const std::string &value)
    {
        if ("north" == value)
            return LaserDirection::North;
        else if ("east" == value)
            return LaserDirection::East;
        else if ("south" == value)
            return LaserDirection::South;
        else if ("west" == value)
            return LaserDirection::West;

        throw "should not happen.";
    }

    static MirrorDirection mirrorDirectionStrToEnum(const std::string &value)
    {
        if ("nw" == value)
            return MirrorDirection::NorthWest;
        else if ("se" == value)
            return MirrorDirection::SouthEast;
        else if ("sw" == value)
            return MirrorDirection::SouthWest;
        else if ("ne" == value)
            return MirrorDirection::NorthEast;

        throw "should not happen.";
    }

    static Position positionStrToPosition(const std::string &value)
    {
        std::size_t dotPos = value.find_first_of(',');

        int x = std::stoi(value.substr(0, dotPos));
        int y = std::stoi(value.substr(dotPos + 1));

        return {x, y};
    }

    static std::string getInput()
    {
        std::string input;

        std::getline(std::cin, input);

        return input;
    }
};

#endif //ENGG1111_ASSIGNMENT1_UTILITY_H
