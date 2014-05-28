#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

string Character::GetName()
{
	getline(cin, m_name);
	return m_name;
}

void Character::SetName(string p_name)
{
	 m_name = p_name;
}