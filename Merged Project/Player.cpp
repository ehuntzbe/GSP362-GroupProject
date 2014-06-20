// Eric H. 6/4
#include "Player.h"


Player* Player::m_Player = NULL;

Player::Player()
{
	/*
	 Hp - 50
	 MP - 30
     strength - 15
     agility - 10
     armor score - 0
	*/
	m_experience = 0;
	m_level = 1;
	m_primeStat = "none";
	m_secondStat = "none";
	m_stats->SetAgi(10);
	m_stats->SetAs(5);
	m_stats->SetExp(0);
	m_stats->SetHp(50);
	m_stats->SetMp(30);
	m_stats->SetStr(15);
	m_stats->SetMaxAgi(10);
	m_stats->SetMaxAs(5);
	m_stats->SetMaxHp(50);
	m_stats->SetMaxMp(30);
	m_stats->SetMaxStr(15);
	m_eqHp = 0;
	m_eqMp = 0;
	m_eqStr = 0;
	m_eqAgi = 0;
	m_eqAs = 0;
	m_bgmusic = false;
}

void Player::SetMusic(int p_value)
{
	if(p_value == 0)
	{
		m_bgmusic = true;
	}

	else
	{
		m_bgmusic = false;
	}
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
	Combatant oldStats;
	Combatant* pOldStats = PC->GetStats();
	oldStats.SetAgi(pOldStats->GetAgi());	oldStats.SetMaxAgi(pOldStats->GetMaxAgi());
	oldStats.SetAs(pOldStats->GetAs());		oldStats.SetMaxAs(pOldStats->GetMaxAs());
	oldStats.SetStr(pOldStats->GetStr());	oldStats.SetMaxStr(pOldStats->GetMaxStr());
	oldStats.SetHp(pOldStats->GetHp());	oldStats.SetMaxHp(pOldStats->GetMaxHp());
	oldStats.SetMp(pOldStats->GetMp());	oldStats.SetMaxMp(pOldStats->GetMaxMp());
	Combatant newStats = oldStats + statsGained; //add stats gained to previous stats
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
		if(input != "y")
		{
			input = "n";
		}
	} while (input == "n");
	
	input = "n";
	string name;
	do
	{
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Your name will be " << name << ". Please confirm this name (y/n): ";
		getline(cin, input);
		if(input != "y")
		{
			input = "n";
		}
	} while (input == "n");
	PC->SetName(name);
	cout << endl << "Welcome to Dark Gun, Apprentice.." << endl;
}

void Player::UnequipItem(Item p_item)
{
	AddItem(m_equipment[p_item.GetWearSlot()]);
	m_equipment[p_item.GetWearSlot()] = Item();
	WorldItems::m_items[p_item.GetItemId()].SetSaveLocation(IN_INVENTORY);
	Combatant statsGained;
	int agi = -p_item.GetAgiBoost();
	int as = -p_item.GetAsBoost();
	int str = -p_item.GetStrBoost();
	int hp = -p_item.GetHpBoost();
	int mp = -p_item.GetMpBoost();
	m_eqHp += hp;
	m_eqMp += mp;
	m_eqAgi += agi;
	m_eqStr += str;
	m_eqAs += as;
	statsGained.SetAgi(agi);	statsGained.SetMaxAgi(agi);
	statsGained.SetAs(as);		statsGained.SetMaxAs(agi);
	statsGained.SetStr(str);	statsGained.SetMaxStr(str);
	statsGained.SetHp(hp);		statsGained.SetMaxHp(hp);
	statsGained.SetMp(mp);		statsGained.SetMaxMp(mp);
	Combatant oldStats;
	Combatant* pOldStats = PC->GetStats();
	oldStats.SetAgi(pOldStats->GetAgi());	oldStats.SetMaxAgi(pOldStats->GetMaxAgi());
	oldStats.SetAs(pOldStats->GetAs());		oldStats.SetMaxAs(pOldStats->GetMaxAs());
	oldStats.SetStr(pOldStats->GetStr());	oldStats.SetMaxStr(pOldStats->GetMaxStr());
	oldStats.SetHp(pOldStats->GetHp());	oldStats.SetMaxHp(pOldStats->GetMaxHp());
	oldStats.SetMp(pOldStats->GetMp());	oldStats.SetMaxMp(pOldStats->GetMaxMp());
	Combatant newStats = oldStats + statsGained; //add stats gained to previous stats
	PC->SetStats(newStats); //set the PC's stats to these new stats
	cout << "You unequip " << p_item.GetShort() << "." << endl;
}

void Player::EquipItem(Item p_item)
{
	if (m_equipment[p_item.GetWearSlot()].GetName() != "none")
		UnequipItem(p_item);
	m_equipment[p_item.GetWearSlot()] = p_item;
	WorldItems::m_items[p_item.GetItemId()].SetSaveLocation(IN_EQUIPMENT);
	RemoveItem(p_item.GetName());
	Combatant statsGained;
	int agi = p_item.GetAgiBoost();
	int as = p_item.GetAsBoost();
	int str = p_item.GetStrBoost();
	int hp = p_item.GetHpBoost();
	int mp = p_item.GetMpBoost();
	m_eqHp += hp;
	m_eqMp += mp;
	m_eqAgi += agi;
	m_eqStr += str;
	m_eqAs += as;
	statsGained.SetAgi(agi);	statsGained.SetMaxAgi(agi);
	statsGained.SetAs(as);		statsGained.SetMaxAs(agi);
	statsGained.SetStr(str);	statsGained.SetMaxStr(str);
	statsGained.SetHp(hp);		statsGained.SetMaxHp(hp);
	statsGained.SetMp(mp);		statsGained.SetMaxMp(mp);
	Combatant oldStats;
	Combatant* pOldStats = PC->GetStats();
	oldStats.SetAgi(pOldStats->GetAgi());	oldStats.SetMaxAgi(pOldStats->GetMaxAgi());
	oldStats.SetAs(pOldStats->GetAs());		oldStats.SetMaxAs(pOldStats->GetMaxAs());
	oldStats.SetStr(pOldStats->GetStr());	oldStats.SetMaxStr(pOldStats->GetMaxStr());
	oldStats.SetHp(pOldStats->GetHp());	oldStats.SetMaxHp(pOldStats->GetMaxHp());
	oldStats.SetMp(pOldStats->GetMp());	oldStats.SetMaxMp(pOldStats->GetMaxMp());
	Combatant newStats = oldStats + statsGained; //add stats gained to previous stats
	PC->SetStats(newStats); //set the PC's stats to these new stats
	cout << "You equip " << p_item.GetShort() << "." << endl;
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

void Player::UpdateAbilityEquations()
{
	m_abilities[0].m_amount = -(PC->GetStats()->GetStr() * 1.5);
	m_abilities[1].m_amount = -(PC->GetStats()->GetStr() * 2.25);
	m_abilities[2].m_amount = 2;
	m_abilities[3].m_amount = PC->GetStats()->GetMaxHp() - PC->GetStats()->GetHp();
	m_abilities[4].m_amount = -(PC->GetStats()->GetStr() * 3);
}
