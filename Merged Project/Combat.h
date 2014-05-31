#include <string>
#include <iostream>
using namespace std;

class Combatant
{
	// Max member varibles
	int m_maxHp;
	int m_maxMp;
	int m_maxStr;
	int m_maxAgi;
	int m_maxAs;

	// Current member variables
	int m_currentHp;
	int m_currentMp;
	int m_currentStr;
	int m_currentAgi;
	int m_currentAs;

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
};

// Combat function prototype
int Combat(Combatant player, Combatant enemy);	// combat function prototype