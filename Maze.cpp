#include "Maze.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

Maze::Maze(int i, int j)
{
	m_field = new MCell[i * j];
	n = i;
	m = j;
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && i2 >= 0 && i2 < n && j2 >= 0 && j2 < m && abs(i1 - i2) + abs(j1 - j2) <= 1)
	    return (i1 == i2 && cell(i1, min(j1, j2)).m_right) || (j1 == j2 && cell(min(i1, i2), j1).m_down);
	return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (i1 < 0 && i1 > n && j1 < 0 && j1 > m && i2 < 0 && i2 > n && j2 < 0 && j2 > m && abs(i1 - i2) + abs(j1 - j2) > 1)
		return false;
	if (i1 == i2)
		m_field[i1 * n + min(j1, j2)].m_right = true;
	else m_field[min(i1, i2) * n + j1].m_down = true;
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (!hasConnection(i1, j1, i2, j2))
		return false;
	if (i1 == i2)
		m_field[i1 * n + min(j1, j2)].m_right = false;
	else m_field[min(i1, i2) * n + j1].m_down = false;
	return true;
}

void Maze::printMaze()
{
	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < m; j++)
		{
			int rightConnection = hasConnection(i, j, i, j + 1) ? 0b0001 : 0b0000;
			int leftConnection = hasConnection(i, j, i, j - 1) ? 0b0010 : 0b0000;
			int upConnection = hasConnection(i, j, i - 1, j) ? 0b0100 : 0b0000;
			int downConnection = hasConnection(i, j, i + 1, j) ? 0b1000 : 0b0000;
			int sumConnection = rightConnection | leftConnection | upConnection | downConnection;
			switch (sumConnection)
			{
			case 0:
				cout << static_cast<char>(248);
				break;
			case 1:
				cout << static_cast<char>(248);
				break;
			case 2:
				cout << static_cast<char>(248);
				break;
			case 3:
				cout << static_cast<char>(196);
				break;
			case 4: 
				cout << static_cast<char>(248);
				break;
			case 5:
				cout << static_cast<char>(192);
				break;
			case 6:
				cout << static_cast<char>(217);
				break;
			case 7:
				cout << static_cast<char>(193);
				break;
			case 8:
				cout << static_cast<char>(248);
				break;
			case 9:
				cout << static_cast<char>(218);
				break;
			case 10:
				cout << static_cast<char>(191);
				break;
			case 11:
				cout << static_cast<char>(194);
				break;
			case 12:
				cout << static_cast<char>(179);
				break;
			case 13:
				cout << static_cast<char>(195);
				break;
			case 14:
				cout << static_cast<char>(180);
				break;
			case 15:
				cout << static_cast<char>(197);
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}