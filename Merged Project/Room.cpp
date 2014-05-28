#include "Room.h"

Room::Room()
{
	//Initialize all pointers to NULL
	m_north = NULL;
	m_south = NULL;
	m_east = NULL;
	m_west = NULL;
	m_up = NULL;
	m_down = NULL;

	for (int i = 0; i < 6; i++)
		m_exits[i] = false;
}

Room::~Room()
{
	//These shouldn't be necessary, but are there just in case.
	if (m_north != NULL)
		delete m_north;
	if (m_south != NULL)
		delete m_south;
	if (m_east != NULL)
		delete m_east;
	if (m_west != NULL)
		delete m_west;
	if (m_up != NULL)
		delete m_up;
	if (m_down != NULL)
		delete m_down;
}

bool Room::N(Room* p_n)
{
	//Confirm that there is no room already connected to the north. If there is a room, somebody is accidentally over-writing a room when they should not be.
	if (m_north != NULL)
		return false;
	m_north = p_n;
	m_exits[NORTH] = true;
	return true;
}

bool Room::S(Room* p_s)
{
	if (m_south != NULL)
		return false;
	m_south = p_s;
	m_exits[SOUTH] = true;
	return true;
}

bool Room::E(Room* p_e)
{
	if (m_east != NULL)
		return false;
	m_east = p_e;
	m_exits[EAST] = true;
	return true;
}

bool Room::W(Room* p_w)
{
	if (m_west != NULL)
		return false;
	m_west = p_w;
	m_exits[WEST] = true;
	return true;
}

bool Room::U(Room* p_u)
{
	if (m_up != NULL)
		return false;
	m_up = p_u;
	m_exits[UP] = true;
	return true;
}

bool Room::D(Room* p_d)
{
	if (m_down != NULL)
		return false;
	m_down = p_d;
	m_exits[DOWN] = true;
	return true;
}

void Room::DisplayExits()
{
	if (m_exits[NORTH] == true)
		cout << " NORTH";
	if (m_exits[SOUTH] == true)
		cout << " SOUTH";
	if (m_exits[EAST] == true)
		cout << " EAST";
	if (m_exits[WEST] == true)
		cout << " WEST";
	if (m_exits[UP] == true)
		cout << " UP";
	if (m_exits[DOWN] == true)
		cout << " DOWN";
}