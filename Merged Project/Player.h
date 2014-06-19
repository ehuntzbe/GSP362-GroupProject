// Eric H. 6/4
#pragma once
#include <string>
#include <iostream>
#include "Character.h"
#include "Room.h"
#include "Combat.h"
#include "Abilities.h"
#include "Items.h"
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
	int m_eqHp;
	int m_eqMp;
	int m_eqAgi;
	int m_eqStr;
	int m_eqAs;
	bool m_bgmusic;
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
	void UpdateAbilityEquations();
	void GenderNamePrompt();
	void UnequipItem(Item p_item);
	void EquipItem(Item p_item);
	void ChangeStatFocus();
	string GetPrimeStat() {return m_primeStat;}
	string GetSecondStat() {return m_secondStat;}
	void SetPrimeStat(string p_primeStat) {m_primeStat = p_primeStat;}
	void SetSecondStat(string p_secondStat) {m_secondStat = p_secondStat;}
	unordered_map<wear_slot, Item> GetEquipment() const {return m_equipment;}
	int GetEqHp() const {return m_eqHp;}
	int GetEqMp() const {return m_eqMp;}
	int GetEqAgi() const {return m_eqAgi;}
	int GetEqStr() const {return m_eqStr;}
	int GetEqAs() const {return m_eqAs;}
	void SetEqHp(int p_hp) {m_eqHp = p_hp;}
	void SetEqMp(int p_mp) {m_eqMp = p_mp;}
	void SetEqAgi(int p_agi) {m_eqAgi = p_agi;}
	void SetEqStr(int p_str) {m_eqStr = p_str;}
	void SetEqAs(int p_as) {m_eqAs = p_as;}
	bool GetMusic() {return m_bgmusic;}
	void SetMusic(int p_value);
};