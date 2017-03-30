#ifndef ENGG1111_ASSIGNMENT1_MAZE_H
#define ENGG1111_ASSIGNMENT1_MAZE_H

#include <vector>

#include "Config.h"
#include "MazeItem.h"
#include "MazeItem/EmptyItem.h"

class Maze
{
public:
    Maze(unsigned int width = Config::MIN_MAZE_WIDTH, unsigned int height = Config::MIN_MAZE_HEIGHT) :
            WIDTH(width)
            , HEIGHT(height)
    {
        maze = std::vector<MazeItem*>(WIDTH * HEIGHT, NULL);

        for (int i = 0; i < HEIGHT; ++i)
        {
            for (int j = 0; j < WIDTH; ++j)
            {
                maze[HEIGHT * i + j] = new EmptyItem({j, i});
            }
        }
    }

    ~Maze()
    {
        std::for_each(maze.cbegin(), maze.cend(), [](MazeItem *item)
        {
            if (item->getType() == MazeItemType::Empty)
            {
                delete item;
                item = NULL;
            }
        });
    }

    bool isSet(const Position pos) const
    {
        if (isOutOfBound(pos))
            return false;

        return get(pos)->getType() != MazeItemType::Empty;
    }

    const MazeItem* get(const Position pos) const
    {
        if (isOutOfBound(pos))
            return NULL;

        return maze[WIDTH * pos.y + pos.x];
    }

    bool set(MazeItem *item)
    {
        if (NULL == item)
            return false;

        const Position pos = item->getPosition();

        if (isOutOfBound(pos))
            return false;

        if (isSet(pos))
            return false;

        if (maze[WIDTH * pos.y + pos.x]->getType() == MazeItemType::Empty)
            delete maze[WIDTH * pos.y + pos.x];

        maze[WIDTH * pos.y + pos.x] = item;

        return true;
    }

    bool isOutOfBound(const Position pos) const
    {
        if (pos.x >= 0 && pos.x < WIDTH
            && pos.y >= 0 && pos.y < HEIGHT)
        {
            return false;
        }

        return true;
    }

private:
    const unsigned int WIDTH;
    const unsigned int HEIGHT;

    std::vector<MazeItem*> maze;
};

#endif //ENGG1111_ASSIGNMENT1_MAZE_H
