#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Room.h"

using namespace std;

const bool DISPLAY_ROOM_ID = true;

class World
{
private:
	int m_roomCount;
	Room* *m_world;
public:
	World();
	~World();
	//Functions that simplify two-way graph connections, return false if attempting to over-write a room.
	bool NS(Room* p_n, Room* p_s);
	bool WE(Room* p_w, Room* p_e);
	bool UD(Room* p_u, Room* p_d);
	void ConfirmConnection(bool p_connection);
	void ConnectRooms();
	void LoadRoomsFromFile(string p_fileName);
	void DisplayRoom(int p_roomID);
};