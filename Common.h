#ifndef ENGG1111_ASSIGNMENT1_COMMON_H
#define ENGG1111_ASSIGNMENT1_COMMON_H

enum class LaserDirection
{
    East
    , South
    , West
    , North
};

enum class MirrorDirection
{
    NorthWest
    , SouthEast
    , SouthWest
    , NorthEast
};

enum class MazeItemType
{
    LaserSource
    , Destination
    , SingleMirror
    , DoubleMirror
    , Block
    , Empty
};

#endif //ENGG1111_ASSIGNMENT1_COMMON_H
