// Eric H. 6/4
#include "Player.h"


Player* Player::m_Player = NULL;

Player::Player()
{
	m_experience = 0;
	m_level = 1;
	m_stats.SetAgi(1);
	m_stats.SetAs(1);
	m_stats.SetExp(0);
	m_stats.SetHp(1);
	m_stats.SetMp(1);
	m_stats.SetStr(1);
	m_stats.SetMaxAgi(1);
	m_stats.SetMaxAs(1);
	m_stats.SetMaxHp(1);
	m_stats.SetMaxMp(1);
	m_stats.SetMaxStr(1);
}

Player* Player::GetInstance()
{
	if (m_Player == NULL)
	{
		m_Player = new Player();
	}
	return m_Player;
}

void Player::LevelUp()
{
	PC->SetLevel(PC->GetLevel()+1);
	Combatant statsGained;
	int agi = 1;
	int as = 1;
	int str = 1;
	int hp = 5;
	int mp = 5;
	statsGained.SetAgi(agi);	statsGained.SetMaxAgi(agi);
	statsGained.SetAs(as);		statsGained.SetMaxAs(agi);
	statsGained.SetStr(str);	statsGained.SetMaxStr(str);
	statsGained.SetHp(hp);		statsGained.SetMaxHp(hp);
	statsGained.SetMp(mp);		statsGained.SetMaxMp(mp);
	Combatant newStats = PC->GetStats() + statsGained; //add stats gained to previous stats
	PC->SetStats(newStats); //set the PC's stats to these new stats
}

void Player::AwardExperience(int p_exp)
{
	m_experience += p_exp;
	if (m_experience >= 100)
	{
		PC->LevelUp(); //go through level up procedure
		PC->AwardExperience(-100); //take away the 100 exp used to level up - done with the function to confirm PC still doesn't have enough to level (EX: 205/100 exp)
	}
}

void Player::AddAbility(ability p_ability)
{
	m_abilities.push_back(p_ability);
}

void Player::GenderNamePrompt()
{
	string input;
	do
	{
		cout << "Enter your gender (m/f): ";
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
			tolower(input[i]);
	} while (input != "m" && input != "f");
	if (input == "m")
		PC->SetDesc("male");
	else
		PC->SetDesc("female");
	
	input = "n";
	string name;
	do
	{
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Your name will be " << name << ". Please confirm this name (y/n): ";
		getline(cin, input);
	} while (input == "n");
	PC->SetName(name);
	cout << "Welcome to the world.." << endl;
}

void Player::EquipItem(Item p_item)
{
	if (m_equipment[p_item.GetWearSlot()].GetName() != "null")
		AddItem(m_equipment[p_item.GetWearSlot()]);
	m_equipment[p_item.GetWearSlot()] = p_item;
	RemoveItem(p_item.GetName());
}