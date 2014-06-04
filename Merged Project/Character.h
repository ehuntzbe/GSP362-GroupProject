#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Combat.h"
#include "ItemStructure.h"
using namespace std;


class Character
{
private:
	string m_name;
	string m_desc;
	Combatant m_stats;
	vector<Item> m_inventory;
public:
	string GetName();				//Get name of Character
	void SetName(string p_name);	//Set name of Character
	Combatant GetStats() const {return m_stats;}
	void SetStats(Combatant temp);
	void DisplayInventory();
	vector<Item> GetInventory() const {return m_inventory;}
	void AddItem(Item p_item) {m_inventory.push_back(p_item);}
};