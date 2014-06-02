#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

enum EXIT
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	UP,
	DOWN
};

class Room
{
private:
	//Each of these Room pointers points to the room they connect to in the graph.
	Room* m_north;
	Room* m_south;
	Room* m_east;
	Room* m_west;
	Room* m_up;
	Room* m_down;
	//Stores the display name of the room
	string m_name;
	//Stores the full description of the room
	string m_desc;
	//Stores whether or not the player is allowed to go through an exit
	bool m_exits[6];
	//Stores Characters
	vector<Character> m_npc;

public:
	//These need to add to the exit list
	//These functions connect the room to another room and return false if attempting to over-write a room.
	bool N(Room* p_n);
	bool S(Room* p_s);
	bool E(Room* p_e);
	bool W(Room* p_w);
	bool U(Room* p_u);
	bool D(Room* p_d);
	string GetName() const {return m_name;}
	void SetName(string p_name) {m_name = p_name;}
	string GetDesc() const {return m_desc;}
	void SetDesc(string p_desc) {m_desc = p_desc;}
	void DisplayExits();
	Room();
	~Room();
};