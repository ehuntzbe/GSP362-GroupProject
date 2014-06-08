// Eric H. 6/4
#include "Player.h"


Player* Player::m_Player = NULL;

Player::Player()
{
	m_experience = 0;
	m_level = 1;
	m_primeStat = "none";
	m_secondStat = "none";
	m_stats.SetAgi(300);
	m_stats.SetAs(100);
	m_stats.SetExp(0);
	m_stats.SetHp(600);
	m_stats.SetMp(500);
	m_stats.SetStr(200);
	m_stats.SetMaxAgi(300);
	m_stats.SetMaxAs(100);
	m_stats.SetMaxHp(600);
	m_stats.SetMaxMp(500);
	m_stats.SetMaxStr(200);
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
	int rngRange = 10;
	if (m_primeStat == "agility")
		rngRange = 20;
	if (m_secondStat == "agility")
		rngRange = 15;
	int agi = 5 + rand()%rngRange;
	rngRange = 10;
	if (m_primeStat == "strength")
		rngRange = 20;
	if (m_secondStat == "strength")
		rngRange = 15;
	int str = 5 + rand()%rngRange;
	rngRange = 10;
	if (m_primeStat == "health")
		rngRange = 20;
	if (m_secondStat == "health")
		rngRange = 15;
	int hp = 10 + rand()%rngRange;
	rngRange = 10;
	if (m_primeStat == "mana")
		rngRange = 20;
	if (m_secondStat == "mana")
		rngRange = 15;
	int mp = 10 + rand()%rngRange;
	int as = 0;
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
	string gender;
	do
	{
		do
		{
			cout << "Enter your gender (m/f): ";
			getline(cin, gender);
			for (int i = 0; i < gender.size(); i++)
				gender[i] = tolower(gender[i]);
		} while (gender != "m" && gender != "f");
		if (gender == "m")
			PC->SetDesc("male");
		else
			PC->SetDesc("female");
		cout << "Your gender will be " << PC->GetDesc() << ". Is that okay? (y/n): ";
		getline(cin, input);
	} while (input == "n");
	
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
	cout << endl << "Welcome to Dark Gun, Apprentice.." << endl;
}

void Player::EquipItem(Item p_item)
{
	if (m_equipment[p_item.GetWearSlot()].GetName() != "null")
		AddItem(m_equipment[p_item.GetWearSlot()]);
	m_equipment[p_item.GetWearSlot()] = p_item;
	RemoveItem(p_item.GetName());
}

void Player::ChangeStatFocus()
{
	string input;
	m_primeStat = "none";
	m_secondStat = "none";
	while (m_primeStat == "none")
	{
		cout << "Would you like your primary stat to be\n"
			"Strength (str)\n"
			"Agility (agi)\n"
			"Mana (mp)\n"
			"Health (hp)?\n"
			"Enter the string in parenthesis to choose your primary stat: ";
		getline(cin, input);
		if (input == "str")
			m_primeStat = "strength";
		if (input == "agi")
			m_primeStat = "agility";
		if (input == "mp")
			m_primeStat = "mana";
		if (input == "hp")
			m_primeStat = "health";
	}
	while (m_secondStat == "none" || m_secondStat == m_primeStat)
	{
		cout << "Would you like your secondary stat to be\n"
			"Strength (str)\n"
			"Agility (agi)\n"
			"Mana (mp)\n"
			"Health (hp)?\n"
			"Enter the string in parenthesis to choose your primary stat (note that your primary and secondary stats must be different): ";
		getline(cin, input);
		if (input == "str")
			m_secondStat = "strength";
		if (input == "agi")
			m_secondStat = "agility";
		if (input == "mp")
			m_secondStat = "mana";
		if (input == "hp")
			m_secondStat = "health";
	}
	cout << "Okay! From now on, your " << m_primeStat << " will grow very quickly, and your " << m_secondStat << " will grow fairly quickly, while all your other stats will grow at a normal rate." << endl;
}