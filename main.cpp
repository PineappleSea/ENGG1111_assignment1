#include <iostream>
#include <vector>

#include "Utility.h"
#include "MazeItem/Block.h"
#include "MazeItem/Destination.h"
#include "MazeItem/LaserSource.h"
#include "MazeItem/SingleMirror.h"
#include "MazeItem/DoubleMirror.h"
#include "Game.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;

    int size = std::stoi(Utility::getInput());
    int numOfItem = std::stoi(Utility::getInput());

    std::vector<MazeItem*> items;

    unsigned int srcId = 1;
    unsigned int destId = 1;

    for (int i = 0; i < numOfItem; ++i)
    {
        std::string itemName;
        std::string direction;
        std::string position;

        std::cin >> itemName;

        MazeItemType itemType = Utility::itemStrToEnum(itemName);

        switch (itemType)
        {
            case MazeItemType::Block:
            {
                std::cin >> position;
                items.push_back( new Block(Utility::positionStrToPosition(position)) );
                break;
            }
            case MazeItemType::Destination:
            {
                std::cin >> position;
                items.push_back( new Destination(Utility::positionStrToPosition(position), destId++) );
                break;
            }
            case MazeItemType::LaserSource:
            {
                std::cin >> direction >> position;
                items.push_back( new LaserSource(Utility::positionStrToPosition(position)
                                                 , Utility::laserDirectionStrToEnum(direction)
                                                 , srcId++)
                );
                break;
            }
            case MazeItemType::SingleMirror:
            {
                std::cin >> direction >> position;
                items.push_back( new SingleMirror(Utility::positionStrToPosition(position)
                        , Utility::mirrorDirectionStrToEnum(direction)) );
                break;
            }
            case MazeItemType::DoubleMirror:
            {
                std::cin >> direction >> position;
                items.push_back( new DoubleMirror(Utility::positionStrToPosition(position)
                        , Utility::mirrorDirectionStrToEnum(direction)) );
                break;
            }
            default:
                break;
        }
    }

    Game game(size, items);

    std::vector<Game::GameResult> results = game.play();

    std::for_each(results.cbegin(), results.cend(), [](const Game::GameResult result)
    {
        std::cout << result.laserSource->getId() << '-';

        if (NULL == result.destination)
            std::cout << 'X';
        else
            std::cout << result.destination->getId();

        std::cout << "\n";
    });

    std::for_each(items.cbegin(), items.cend(), [](const MazeItem *item)
    {
        delete item;
        item = NULL;
    });

    return 0;
}
