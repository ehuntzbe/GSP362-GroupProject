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
}

void Inventory()
{
	PC->DisplayInventory();
}

void Abilities()
{
	vector<ability> pcAbil = PC->GetAbilities();
	for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
	{
		if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		cout << "Name: " << it->m_name << endl;
		cout << "Description: " << it->m_desc << endl;
		cout << "Cool Down: " << it->m_cooldown << endl;
		cout << "HP Cost: " << it->m_hpCost << endl;
		cout << "MP Cost: " << it->m_mpCost << endl;
		cout << "Target: " << it->m_target << endl;
		cout << "Affects: " << it->m_type << endl;
		cout << "Amount: " << it->m_amount << endl;
		cout << "testing" << endl;
	}
}