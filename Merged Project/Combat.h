// Eric H. 6/4
#pragma once
#include <string>
#include <iostream>
using namespace std;

enum combat_outcome {DEAD, FLED, KILLED};

class Combatant
{
	// Max member varibles
	int m_maxHp; //player's total health
	int m_maxMp; //player's total mana
	int m_maxStr; //player's normal strength
	int m_maxAgi; //player's normal agility
	int m_maxAs; //player's normal armor score (defense)
	
	// Current member variables
	int m_currentHp; //player's current health
	int m_currentMp; //player's current mana
	int m_currentStr; //player's current strength (can be modified by buffs and debuffs)
	int m_currentAgi; //current agility
	int m_currentAs; //current armor score (defense)

	int m_Exp;	// Experience

public:
	//Getters for Max stats
	int GetMaxHp()		const	{ return m_maxHp; }
	int GetMaxMp()		const	{ return m_maxMp; }
	int GetMaxStr()		const	{ return m_maxStr; }
	int GetMaxAgi()		const	{ return m_maxAgi; }
	int GetMaxAs()		const	{ return m_maxAs; }

	//Getters for Current stats
	int GetHp()					{ return m_currentHp; }
	int GetMp()					{ return m_currentMp; }
	int GetStr()				{ return m_currentStr; }
	int GetAgi()				{ return m_currentAgi; }
	int GetAs()					{ return m_currentAs; }

	int GetExp()				{ return m_Exp; }	// Getter for experience

	//Setters for Max stats
	void SetMaxHp(int p_hp)		{ m_maxHp = p_hp; }
	void SetMaxMp(int p_mp)		{ m_maxMp = p_mp; }
	void SetMaxStr(int p_str)	{ m_maxStr = p_str; }
	void SetMaxAgi(int p_agi)	{ m_maxAgi = p_agi; }
	void SetMaxAs(int p_as)		{ m_maxAs = p_as; }

	//Setters for Current stats
	void SetHp(int p_hp)		{ m_currentHp = p_hp; }
	void SetMp(int p_mp)		{ m_currentMp = p_mp; }
	void SetStr(int p_str)		{ m_currentStr = p_str; }
	void SetAgi(int p_agi)		{ m_currentAgi = p_agi; }
	void SetAs(int p_as)		{ m_currentAs = p_as; }

	void SetExp(int p_exp)		{ m_Exp = p_exp; }	// Setter for experience

	Combatant operator+(Combatant p_other);
};

// Combat function prototype
combat_outcome Combat(Combatant player, Combatant enemy);	// combat function prototype
