// Cory Jacobs 05/28/2014 12:06pm
#pragma once
#include <string>
#include <iostream>
#include "Character.h"
#include "Room.h"
#include "Combat.h"
using namespace std;

/*
-PC needs exp
-PC needs level, level ups, and stat ups from level ups
-PC needs to unlock abilities from level ups
-PC needs a variable to store the current room s/he's in
*/

/*
This class is a singleton.
*/
class Player
{
private:
	string m_abilName;
	string m_abilDesc;
	
	int m_experience;
	int m_level;
	int m_stats;
	
	//Constructor is private for singleton implementation
	Player();
	static Player* m_Player;
	Room*   m_currentRoom;

public:
	string GetAbilites();	//Get the abilities for player after a level up
	void SetAbilites(string p_abilName);	//Set the abilities for a level up
	//Getters
	int GetExperience();
	int GetLevel();					
	int GetStats();					
	//Setters
	void SetExperience(int p_exp)		{ m_experience = p_exp; } 	
	void SetLevel(int p_lvl)			{ m_level = p_lvl; }
	void SetStats(int p_stt)			{ m_stats = p_stt; }
	//Access the instance of Player
	static Player* GetInstance();
	//Access the instance of Room
	Room* GetCurrentRoom();
	void SetCurrentRoom(Room* p_room);
};