#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Room.h"
#include "Player.h"

using namespace std;

const bool DISPLAY_ROOM_ID = true;
#define WORLD World::GetInstance()

//Using singleton structure
class World
{
private:
	int m_roomCount;
	Room* *m_world;
	static World* m_instance;
	World();
	~World();
public:
	//Functions that simplify two-way graph connections, return false if attempting to over-write a room.
	bool NS(Room* p_n, Room* p_s);
	bool WE(Room* p_w, Room* p_e);
	bool UD(Room* p_u, Room* p_d);
	void ConfirmConnection(bool p_connection);
	void ConnectRooms();
	void LoadRoomsFromFile(string p_fileName, string p_npcFileName);
	void LoadNpcsFromFile(string p_npcFileName, Room* p_room);
	void DisplayRoom(int p_roomID);
	int RoomCount();
	static World* GetInstance();
};