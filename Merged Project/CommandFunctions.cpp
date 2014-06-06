//Cory J 6/5
#include "CommandFunctions.h"

void Look()
{
	cout << PC->GetCurrentRoom()->GetName() << endl;
	cout << PC->GetCurrentRoom()->GetDesc() << endl;
	cout << "EXITS:"; PC->GetCurrentRoom()->DisplayExits(); cout << endl;
	cout << "-Others here with you-" << endl;
	if (PC->GetCurrentRoom()->GetNumNpc() > 0)
	{
		vector<Character> others = PC->GetCurrentRoom()->NpcList();
		for (vector<Character>::iterator it = others.begin(); it != others.end(); ++it)
		{
			cout << it->GetDesc() << endl;
		}
	}
	else
		cout << "Nobody." << endl;
}

void Kill(Character* p_target)
{
	if (PC->GetCurrentRoom()->GetNPC(p_target->GetName()).GetName() != "NULL")
		Combat(PC->GetStats(), p_target->GetStats());
}

void North()
{
	if (PC->GetCurrentRoom()->CheckExit(NORTH))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetN());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void South()
{
	if (PC->GetCurrentRoom()->CheckExit(SOUTH))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetS());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void East()
{
	if (PC->GetCurrentRoom()->CheckExit(EAST))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetE());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void West()
{
	if (PC->GetCurrentRoom()->CheckExit(WEST))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetW());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void Up()
{
	if (PC->GetCurrentRoom()->CheckExit(UP))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetU());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void Down()
{
	if (PC->GetCurrentRoom()->CheckExit(DOWN))
	{
		PC->SetCurrentRoom(PC->GetCurrentRoom()->GetD());
		Look();
	}
	else
		cout << "There is no exit that way." << endl;
}

void Score()
{
	//Output score screen
	cout << "Name: " << PC->GetName() << endl;
	cout << "Level: " << PC->GetLevel() << endl;
	cout << "Exp: " << PC->GetExperience() << endl;
	cout << "HP: " <<  PC->GetStats().GetHp() << "/" << PC->GetStats().GetMaxHp() << endl;
	cout << "MP: " <<  PC->GetStats().GetMp() << "/" << PC->GetStats().GetMaxMp() << endl;
	cout << "Strength: " <<  PC->GetStats().GetStr() << endl;
	cout << "Agility: " <<  PC->GetStats().GetAgi() << endl;
	cout << "Armor: " << PC->GetStats().GetAs() << endl;
}

void Inventory()
{
	PC->DisplayInventory();
}

void Abilities()
{
	vector<ability> pcAbil = PC->GetAbilities();

	bool bContinue = true;
	int userInput; // Holds the key pressed by the user

	int i = 0;
	for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
	{
		i++;
		if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		{
			cout << "Ability " << i << ": " << it->m_name << endl;
			cout << endl;
		}
		cout << "Enter the number of the ability to see its full effects: ";
		cin >> userInput;
		cin.clear();

		if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		{
			cout << "Name: " << pcAbil[i].m_name << endl;
			cout << "Description: " << pcAbil[i].m_desc << endl;
			cout << "Cool Down: " << pcAbil[i].m_cooldown << endl;
			cout << "HP Cost: " << pcAbil[i].m_hpCost << endl;
			cout << "MP Cost: " << pcAbil[i].m_mpCost << endl;
			cout << "Target: " << pcAbil[i].m_target << endl;
			cout << "Affects: " << pcAbil[i].m_type << endl;
			cout << "Damage: " << pcAbil[i].m_amount << endl;
		}
		else
		{
			cout << "That is not an unlocked ability." << endl;
		}
	}

	while ( bContinue )
	{
		cout << "\nA list of Abilities by name\n" << endl;
		cout << "Mana Bullet" << endl;
		cout << "Mana Beam" << endl;
		cout << "Mana Surge" << endl;
		cout << "Mana Sync" << endl;
		cout << "Exit\n" << endl;


		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Name: " << it->m_name << endl;
				cout << "Description: " << it->m_desc << endl;
				cout << "Cool Down: " << it->m_cooldown << endl;
				cout << "HP Cost: " << it->m_hpCost << endl;
				cout << "MP Cost: " << it->m_mpCost << endl;
				cout << "Target: " << it->m_target << endl;
				cout << "Affects: " << it->m_type << endl;
				cout << "Damage: " << it->m_amount << endl;
				cout << endl;
			}
		}

		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Name: " << it->m_name << endl;
				cout << "Description: " << it->m_desc << endl;
				cout << "Cool Down: " << it->m_cooldown << endl;
				cout << "HP Cost: " << it->m_hpCost << endl;
				cout << "MP Cost: " << it->m_mpCost << endl;
				cout << "Target: " << it->m_target << endl;
				cout << "Affects: " << it->m_type << endl;
				cout << "Damage: " << it->m_amount << endl;
				cout << endl;
			}
		}


		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Name: " << it->m_name << endl;
				cout << "Description: " << it->m_desc << endl;
				cout << "Cool Down: " << it->m_cooldown << endl;
				cout << "HP Cost: " << it->m_hpCost << endl;
				cout << "MP Cost: " << it->m_mpCost << endl;
				cout << "Target: " << it->m_target << endl;
				cout << "Affects: " << it->m_type << endl;
				cout << "Damage: " << it->m_amount << endl;
				cout << endl;
			}
		}

		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Name: " << it->m_name << endl;
				cout << "Description: " << it->m_desc << endl;
				cout << "Cool Down: " << it->m_cooldown << endl;
				cout << "HP Cost: " << it->m_hpCost << endl;
				cout << "MP Cost: " << it->m_mpCost << endl;
				cout << "Target: " << it->m_target << endl;
				cout << "Affects: " << it->m_type << endl;
				cout << "Damage: " << it->m_amount << endl;
				cout << endl;
			}
		}
	}

	if( userInput == 5 )
	{
		Interface::GetInstance()->MainGame();
	}
}