#pragma once
class MCell
{	
public:
	bool right();
	bool down();
	friend class Maze;
private:
	bool m_down;
	bool m_right;
	MCell();
};

