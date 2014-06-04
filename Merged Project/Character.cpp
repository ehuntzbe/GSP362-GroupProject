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

void Character::SetStats(Combatant p_stats)
{	
	m_stats.SetMaxHp(p_stats.GetMaxHp());		
	m_stats.SetMaxMp(p_stats.GetMaxMp());		
	m_stats.SetMaxStr(p_stats.GetMaxStr());	
	m_stats.SetMaxAgi(p_stats.GetMaxAgi());	
	m_stats.SetMaxAs(p_stats.GetMaxAs());		
	m_stats.SetHp(p_stats.GetHp());		
	m_stats.SetMp(p_stats.GetMp());		
	m_stats.SetStr(p_stats.GetStr());		
	m_stats.SetAgi(p_stats.GetAgi());		
	m_stats.SetAs(p_stats.GetAs());		
	m_stats.SetExp(p_stats.GetExp());	
}