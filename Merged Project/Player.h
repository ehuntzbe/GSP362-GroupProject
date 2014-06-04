// Eric H. 6/4
#pragma once
#include <string>
#include <iostream>
#include "Character.h"
#include "Room.h"
#include "Combat.h"
#include "Abilities.h"
using namespace std;

#define PC Player::GetInstance()
struct ability;

/*
-PC needs exp
-PC needs level, level ups, and stat ups from level ups
-PC needs to unlock abilities from level ups
-PC needs a variable to store the current room s/he's in
*/


/*
This class is a singleton.
*/
class Player : public Character
{
private:	
	int m_experience;
	int m_level;
	Room* m_currentRoom;
	vector<ability> m_abilities; //all abilities (not just unlocked ones)
	//Constructor is private for singleton implementation
	Player();
	static Player* m_Player;

public:
	int GetExperience() const {return m_experience;}
	int GetLevel() const {return m_level;}
	Room* GetCurrentRoom() const {return m_currentRoom;}
	void SetExperience(int p_exp) { m_experience = p_exp; }
	void AwardExperience(int p_exp);
	void SetLevel(int p_lvl) { m_level = p_lvl; }
	void LevelUp();
	void SetCurrentRoom(Room* p_room) {m_currentRoom = p_room;}
	//Access the instance of Player
	static Player* GetInstance();
	void AddAbility(ability p_ability);
	void GenderNamePrompt();
};