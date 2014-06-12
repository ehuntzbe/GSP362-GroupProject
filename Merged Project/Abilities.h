// Eric H. 6/4
#pragma once
#include "Player.h"

enum target {ENEMY, SELF};
enum type {HP, MP, AS, STR, AGI};

struct ability
{
	ability() {m_name = "none"; m_desc = "none";}
	int m_mpCost; //mp cost to use the ability
	int m_hpCost; //hp cost to use the ability
	int m_cooldown; //number of rounds before you can use this ability again
	int m_unlockLevel; //level the player gains this ability
	target m_target; //target of the ability
	type m_type; //variable target of the ability
	int m_amount; //amount to change the variable
	string m_name; //name displayed in the ability list
	string m_desc; //description given when ability is used
	bool IsUnlocked() const; //returns whether or not the unlock level is lower than the player's level
	static void UpdateAbilities();
};