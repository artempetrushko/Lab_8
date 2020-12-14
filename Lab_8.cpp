#include <iostream>
#include "Maze.h"

int main()
{
    auto maze = new Maze(5, 5);
    for (auto i = 0; i < 5; i++)
    {
        maze->makeConnection(i, i, i, i + 1);
        maze->makeConnection(i, i + 1, i + 1, i + 1);
    }
    maze->printMaze();
    system("pause");
    return 0;
}
