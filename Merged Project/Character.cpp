// Eric H. 6/4
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

Character::Character()
{
	m_name = "none";
	m_stats = new Combatant();
}

string Character::GetName() const
{
	return m_name;
}

void Character::SetName(string p_name)
{
	 m_name = p_name;
}

string Character::GetDesc() const
{
	return m_desc;
}

void Character::SetDesc(string p_desc)
{
	m_desc = p_desc;
}

void Character::SetStats(Combatant p_stats)
{	
	m_stats->SetMaxHp(p_stats.GetMaxHp());		
	m_stats->SetMaxMp(p_stats.GetMaxMp());		
	m_stats->SetMaxStr(p_stats.GetMaxStr());	
	m_stats->SetMaxAgi(p_stats.GetMaxAgi());	
	m_stats->SetMaxAs(p_stats.GetMaxAs());		
	m_stats->SetHp(p_stats.GetHp());		
	m_stats->SetMp(p_stats.GetMp());		
	m_stats->SetStr(p_stats.GetStr());		
	m_stats->SetAgi(p_stats.GetAgi());		
	m_stats->SetAs(p_stats.GetAs());		
	m_stats->SetExp(p_stats.GetExp());	
}

void Character::RemoveItem(string p_itemName)
{
	for (list<Item>::iterator it = m_inventory.begin(); it != m_inventory.end(); ++it)
	{
		if (it->GetName() == p_itemName)
		{
			m_inventory.erase(it);
			break;
		}
	}
}