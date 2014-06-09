#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "ItemStructure.h"
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
	vector<Character> m_npcs;
	//Stores number of Characters
	int m_Numnpcs;
	//Stores items
	vector<Item> m_items;

public:
	//These need to add to the exit list
	//These functions connect the room to another room and return false if attempting to over-write a room.
	bool N(Room* p_n);
	bool S(Room* p_s);
	bool E(Room* p_e);
	bool W(Room* p_w);
	bool U(Room* p_u);
	bool D(Room* p_d);
	Room* GetN() const {return m_north;}
	Room* GetS() const {return m_south;}
	Room* GetE() const {return m_east;}
	Room* GetW() const {return m_west;}
	Room* GetU() const {return m_up;}
	Room* GetD() const {return m_down;}
	string GetName() const {return m_name;}
	void SetName(string p_name) {m_name = p_name;}
	string GetDesc() const {return m_desc;}
	void SetDesc(string p_desc) {m_desc = p_desc;}
	int GetNumNpc() const {return m_Numnpcs;}
	void SetNumNpc(string p_num) {m_Numnpcs = atoi(p_num.c_str());}
	void DisplayExits();
	void NpcResize(int size);
	void NpcAdd(Character p_npc);
	void RemoveNpc(string p_name);
	void RemoveItem(string p_name);
	vector<Character> NpcList() {return m_npcs;}
	Character GetNPC(string p_name);
	vector<Item> ItemList() {return m_items;}
	void AddItem(Item p_item) {m_items.push_back(p_item);}
	Item GetItem(string p_name);
	bool CheckExit(EXIT p_exit) const {if (m_exits[p_exit] == true) return true; return false;}
	Room();
	~Room();
};