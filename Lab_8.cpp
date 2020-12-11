#include <iostream>
#include "Maze.h"

int main()
{
    auto maze = new Maze(5, 5);
    maze->makeConnection(0, 0, 0, 1);
    maze->makeConnection(0, 1, 1, 1);
    maze->makeConnection(1, 1, 1, 2);
    maze->makeConnection(1, 2, 2, 2);
    maze->makeConnection(2, 2, 2, 3);
    maze->makeConnection(2, 3, 3, 3);
    maze->makeConnection(3, 3, 3, 4);
    maze->makeConnection(3, 4, 4, 4);
    maze->printMaze();
    system("pause");
    return 0;
}
