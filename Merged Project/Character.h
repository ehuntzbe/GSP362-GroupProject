// Eric H. 6/4
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "Combat.h"
#include "ItemStructure.h"
using namespace std;


class Character
{
private:
	string m_name;
	string m_desc;
	list<Item> m_inventory;
protected:
	Combatant m_stats;
public:
	string GetName() const;				//Get name of Character
	void SetName(string p_name);	//Set name of Character
	string GetDesc() const;
	void SetDesc(string p_desc);
	Combatant GetStats() const {return m_stats;}
	void SetStats(Combatant p_stats);
	list<Item> GetInventory() const {return m_inventory;}
	void AddItem(Item p_item) {m_inventory.push_back(p_item);}
	void RemoveItem(string p_itemName);
};