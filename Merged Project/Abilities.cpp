// Eric H. 6/4
#include "Abilities.h"


bool ability::IsUnlocked() const
{
	return (m_unlockLevel <= PC->GetLevel());
}

string ability::GetType()
{
	switch(m_type)
	{
	case HP:
		return "HP";
	case MP:
		return "MP";
	case AGI:
		return "AGI";
	case STR:
		return "STR";
	case AS:
		return "AS";
	}
}

void ability::AddAbilities()
{
	//Here are some sample abilities
	PC->ResetAbilities();
	ability abBuf;

	abBuf.m_name = "Mana Bullet"; //simple ability that gives up mana for an increased damage shot (reduces ENEMY's HP)
	abBuf.m_desc = "You fire a simple bullet of mana at the enemy.\n";
	abBuf.m_unlockLevel = 1;
	abBuf.m_cooldown = 0;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 2;
	abBuf.m_target = ENEMY;
	abBuf.m_type = HP;
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Beam"; //higher mana cost, higher damage, a 1-round cooldown
	abBuf.m_desc = "You fire a beam of mana at the enemy.\n";
	abBuf.m_unlockLevel = 2;
	abBuf.m_cooldown = 1;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 4;
	abBuf.m_target = ENEMY;
	abBuf.m_type = HP;
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Surge"; //buffs the players strength by 2 for 4 rounds at a 4 round cooldown
	abBuf.m_desc = "You pump mana through the veins of your muscles,\nincreasing the power of your attacks.\n";
	abBuf.m_unlockLevel = 5;
	abBuf.m_cooldown = 4;
	abBuf.m_hpCost = 2;
	abBuf.m_mpCost = 2;
	abBuf.m_target = SELF;
	abBuf.m_type = STR;
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Synchronization"; //full heal
	abBuf.m_desc = "You synchronize with the mana of the world,\nhealing your wounds completely.\n";
	abBuf.m_unlockLevel = 15;
	abBuf.m_cooldown = 3;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 20;
	abBuf.m_target = SELF;
	abBuf.m_type = HP;
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Bomb"; //higher mana cost, higher damage, a 3-round cooldown
	abBuf.m_desc = "You throw a bomb made of mana at the enemy.\n";
	abBuf.m_unlockLevel = 10;
	abBuf.m_cooldown = 3;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 30;
	abBuf.m_target = ENEMY;
	abBuf.m_type = HP;
	PC->AddAbility(abBuf);

	PC->UpdateAbilityEquations();
}