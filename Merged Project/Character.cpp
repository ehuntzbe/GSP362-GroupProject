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