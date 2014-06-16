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
	NONE, HEAD, SHOULDERS, ARMS, 
	HANDS, OFFHAND,
	BODY, LEGS, FEET
};

enum save_location
{
	NOWHERE, IN_INVENTORY, IN_EQUIPMENT, IN_ROOM, IN_NPC
};

enum type;

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
	//Save and load data
	save_location m_location;
	int m_roomId;
	string m_npcName;
	int m_itemId;

	type m_useItemAffect;
	int m_useItemAmount;

public:
	Item();
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
	save_location GetSaveLocation() const {return m_location;}
	int GetRoomId()		const	{ return m_roomId; }
	string GetNpcName()		const	{ return m_npcName; }
	type GetUseAffect()	const	{ return m_useItemAffect; }
	int GetUseAffectAmount() const	{ return m_useItemAmount; }
	int GetItemId() const {return m_itemId;}
	//Setters
	void SetWearSlot(wear_slot p_wearSlot) { m_wearSlot = p_wearSlot; }
	void SetHpBoost(int hp)		{ m_hpBoost = hp; }
	void SetMpBoost(int mp)		{ m_mpBoost = mp; }
	void SetStrBoost(int str)	{ m_strBoost = str; }
	void SetAgiBoost(int agi)	{ m_agiBoost = agi; }
	void SetAsBoost(int as)		{ m_asBoost = as; }
	void SetName(string p_name)	{ m_itemName = p_name; }
	void SetDesc(string p_desc)	{ m_desc = p_desc; }
	void SetShort(string p_short)	{ m_shortDesc = p_short; }
	void SetSaveLocation(save_location p_loc) {m_location = p_loc;}
	void SetRoomId(int p_id) {m_roomId = p_id;}
	void SetNpcName(string p_name) {m_npcName = p_name;}
	void SetUseAffect(type p_affect) {m_useItemAffect = p_affect;}
	void SetUseAffectAmount(int p_amt) {m_useItemAmount = p_amt;}
	void SetItemId(int p_id) {m_itemId = p_id;}
};