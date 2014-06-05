// Eric H. 6/4
#include "Abilities.h"


bool ability::IsUnlocked() const
{
	return (m_unlockLevel <= PC->GetLevel());
}

void ability::AddAbilities()
{
	//Here are some sample abilities
	ability abBuf;

	abBuf.m_name = "Mana Bullet"; //simple ability that gives up mana for an increased damage shot (reduces ENEMY's HP)
	abBuf.m_desc = "You fire a simple bullet of mana at the enemy.";
	abBuf.m_unlockLevel = 1;
	abBuf.m_cooldown = 0;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 2;
	abBuf.m_target = ENEMY;
	abBuf.m_type = HP;
	abBuf.m_amount = -(PC->GetStats().GetStr() * 1.5);
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Beam"; //higher mana cost, higher damage, a 1-round cooldown
	abBuf.m_desc = "You fire a beam of mana at the enemy.";
	abBuf.m_unlockLevel = 2;
	abBuf.m_cooldown = 1;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 4;
	abBuf.m_target = ENEMY;
	abBuf.m_type = HP;
	abBuf.m_amount = -(PC->GetStats().GetStr() * 2.25);
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Surge"; //buffs the players strength by 2 for 4 rounds at a 4 round cooldown
	abBuf.m_desc = "You pump mana through the veins of your muscles, increasing the power of your attacks.";
	abBuf.m_unlockLevel = 5;
	abBuf.m_cooldown = 4;
	abBuf.m_hpCost = 2;
	abBuf.m_mpCost = 2;
	abBuf.m_target = SELF;
	abBuf.m_type = STR;
	abBuf.m_amount = 2;
	PC->AddAbility(abBuf);

	abBuf.m_name = "Mana Synchronization"; //full heal
	abBuf.m_desc = "You synchronize with the mana of the world, healing your wounds completely.";
	abBuf.m_unlockLevel = 15;
	abBuf.m_cooldown = 3;
	abBuf.m_hpCost = 0;
	abBuf.m_mpCost = 20;
	abBuf.m_target = SELF;
	abBuf.m_type = HP;
	abBuf.m_amount = PC->GetStats().GetMaxHp() - PC->GetStats().GetHp();
	PC->AddAbility(abBuf);
}