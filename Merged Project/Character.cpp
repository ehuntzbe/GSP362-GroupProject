#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

string Character::GetName()
{
	return m_name;
}

void Character::SetName(string p_name)
{
	 m_name = p_name;
}

void Character::DisplayInventory()
{
	cout << "You are carrying " << m_inventory.size() << " items in your inventory." << endl;
	for (vector<Item>::iterator it = m_inventory.begin(); it != m_inventory.end(); ++it)
	{
		cout << it->GetShort() << endl;
	}
	cout << endl;
}

void Character::SetStats(Combatant temp)
{	
	m_stats.SetMaxHp(temp.GetMaxHp());		
	m_stats.SetMaxMp(temp.GetMaxMp());		
	m_stats.SetMaxStr(temp.GetMaxStr());	
	m_stats.SetMaxAgi(temp.GetMaxAgi());	
	m_stats.SetMaxAs(temp.GetMaxAs());		
	m_stats.SetHp(temp.GetHp());		
	m_stats.SetMp(temp.GetMp());		
	m_stats.SetStr(temp.GetStr());		
	m_stats.SetAgi(temp.GetAgi());		
	m_stats.SetAs(temp.GetAs());		
	m_stats.SetExp(temp.GetExp());	
}