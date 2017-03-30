cmake_minimum_required(VERSION 3.6)
project(ENGG1111_assignment1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Config.h Position.h Common.h Utility.h Maze.h MazeItem.h MazeItem/LaserSource.h MazeItem/SingleMirror.h MazeItem/DoubleMirror.h MazeItem/Destination.h MazeItem/Block.h MazeItem/EmptyItem.h Game.h)
add_executable(ENGG1111_assignment1 ${SOURCE_FILES})