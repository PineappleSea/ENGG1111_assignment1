#ifndef ENGG1111_ASSIGNMENT1_GAME_H
#define ENGG1111_ASSIGNMENT1_GAME_H

#include <vector>

#include "MazeItem/LaserSource.h"
#include "MazeItem/Destination.h"
#include "Maze.h"

class Game
{
public:
    struct GameResult
    {
    public:
        LaserSource *laserSource = NULL;
        Destination *destination = NULL;
    };

    Game(unsigned int mazeSize, const std::vector<MazeItem*> items) :
            maze(mazeSize, mazeSize)
    {
        std::for_each(items.cbegin(), items.cend(), [&](MazeItem *item)
        {
            maze.set(item);

            if (item->getType() == MazeItemType::LaserSource)
                laserSourceList.push_back(item);
            else if (item->getType() == MazeItemType::Destination)
                destinationList.push_back(item);
        });
    }

    std::vector<GameResult> play() const
    {
        std::vector<GameResult> results;

        std::for_each(laserSourceList.cbegin(), laserSourceList.cend(), [&](const MazeItem* item)
        {
            const LaserSource* laserSource = dynamic_cast<const LaserSource*>(item);

//            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//            std::cout << "laser src id = " << laserSource->getId() << "\n";

            Position nextPos = laserSource->startLaser();

            GameResult gameResult;

            gameResult.laserSource = const_cast<LaserSource*>(laserSource);

            LaserDirection currLaserDirection = laserSource->getLaserDirection();

            bool finish = false;

            while (!finish)
            {
                MazeItem *currItem = const_cast<MazeItem*>(maze.get(nextPos));

//                std::cout << "---------\n";
//                std::cout << nextPos.x << ',' << nextPos.y << '\n';
//
//                if (currItem)
//                    std::cout << "currItem = " <<  (int)currItem->getType() << "\n";
//                else
//                    std::cout << "currItem = NULL\n";
//
//                std::cout << "laserDirection = " << (int)currLaserDirection << "\n";

                if (NULL == currItem)
                {
                    finish = true;
                }
                else
                {
                    std::tuple<bool, Position, LaserDirection> tuple = currItem->handle(currLaserDirection);

                    if (std::get<0>(tuple)) // isFinish
                    {
                        MazeItem *finishItem = const_cast<MazeItem*>(maze.get(std::get<1>(tuple)));

                        if (NULL != finishItem
                            && finishItem->getType() == MazeItemType::Destination)
                        {
                            gameResult.destination = dynamic_cast<Destination*>(finishItem);
                        }

                        finish = true;
                    }
                    else
                    {
                        currLaserDirection = std::get<2>(tuple);
                        nextPos = std::get<1>(tuple);
                    }
                }
            }

            results.push_back(gameResult);

        });

        return results;
    }

private:
    Maze maze;

    std::vector<MazeItem*> laserSourceList;
    std::vector<MazeItem*> destinationList;
};

#endif //ENGG1111_ASSIGNMENT1_GAME_H
