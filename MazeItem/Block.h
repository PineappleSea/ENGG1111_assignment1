#ifndef ENGG1111_ASSIGNMENT1_BLOCK_H
#define ENGG1111_ASSIGNMENT1_BLOCK_H

#include "../MazeItem.h"

class Block : public MazeItem
{
public:
    Block(const Position &position) :
            MazeItem(position, MazeItemType::Block)
    {
    }

    std::tuple<bool, Position, LaserDirection> handle(LaserDirection laserDirection) override
    {
        return {true, this->getPosition(), laserDirection};
    }
};

#endif //ENGG1111_ASSIGNMENT1_BLOCK_H
