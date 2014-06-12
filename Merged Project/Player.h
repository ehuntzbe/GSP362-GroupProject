// Eric H. 6/4
#pragma once
#include <string>
#include <iostream>
#include "Character.h"
#include "Room.h"
#include "Combat.h"
#include "Abilities.h"
#include <unordered_map>
using namespace std;

#define PC Player::GetInstance()
struct ability;

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
	unordered_map<wear_slot, Item> m_equipment; //equipment slots
	//Constructor is private for singleton implementation
	Player();
	static Player* m_Player;
	string m_primeStat;
	string m_secondStat;

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
	void ResetAbilities() {m_abilities.clear();}
	vector<ability> GetAbilities() const {return m_abilities;}
	void GenderNamePrompt();
	void UnequipItem(Item p_item);
	void EquipItem(Item p_item);
	void ChangeStatFocus();
	unordered_map<wear_slot, Item> GetEquipment() const {return m_equipment;}
};