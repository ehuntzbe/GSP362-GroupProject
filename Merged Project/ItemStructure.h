#pragma once
#ifndef __ITEMSTRUCTURE_H__
#define __ITEMSTRUCTURE_H__
#endif

#include <string>
using namespace std;

/*
An enumerator that lists all the wear slots.
A generic item class or structure that should contain.
-all the stat modifier variables
-a string name
-a string description
-a variable holdig the enumeration you made
-functions to get and set all those variables
*/

enum wear_slot
{
	HEAD, SHOULDERS, ARMS, 
	HANDS, OFFHAND, MAINHAND, 
	BODY, LEGS, FEET
};

class Item
{
private:
	string m_itemName;
	string m_shortDesc;
	string m_desc;
	wear_slot m_wearSlot;
	int m_hpBoost;
	int m_mpBoost;
	int m_strBoost;
	int m_agiBoost;
	int m_asBoost;

public:
	//Getters
	wear_slot GetWearSlot() const { return m_wearSlot; }
	int GetHpBoost()	const	{ return m_hpBoost; }
	int GetMpBoost()	const	{ return m_mpBoost; }
	int GetStrBoost()	const	{ return m_strBoost; }
	int GetAgiBoost()	const	{ return m_agiBoost; }
	int GetAsBoost()	const	{ return m_asBoost; }
	string GetName()	const	{ return m_itemName; }
	string GetDesc()	const	{ return m_desc; }
	string GetShort()	const	{ return m_shortDesc; }
	//Setters
	wear_slot SetWearSlot() const { return m_wearSlot; }
	void SetHpBoost(int hp)		{ m_hpBoost = hp; }
	void SetMpBoost(int mp)		{ m_mpBoost = mp; }
	void SetStrBoost(int str)	{ m_strBoost = str; }
	void SetAgiBoost(int agi)	{ m_hpBoost = agi; }
	void SetAsBoost(int as)		{ m_hpBoost = as; }
	void SetName(string p_name)	{ m_itemName = p_name; }
	void SetDesc(string p_desc)	{ m_desc = p_desc; }
	void SetShort(string p_short)	{ m_shortDesc = p_short; }
};