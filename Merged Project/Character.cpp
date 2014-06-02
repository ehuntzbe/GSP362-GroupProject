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