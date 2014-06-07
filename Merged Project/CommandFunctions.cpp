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

void Kill(string p_target)
{
	combat_outcome battle;
	Room* room = PC->GetCurrentRoom();
	Character opponent = room->GetNPC(p_target);
	if (opponent.GetName() != "NULL")
	{
		battle = Combat(PC->GetStats(), opponent.GetStats());
		switch (battle)
		{
		case DEAD:
			cout << "Game over." << endl;
			system("pause");
			exit(0);
			break;
		case FLED:
			//I don't think anything happens here, we can decide if we do want something to happen other than ending combat
			//Remove debuffs placed on the player and enemy?
			break;
		case KILLED:
			if (opponent.GetInventory().size() > 0)
			{
				list<Item> loot = opponent.GetInventory();
				for (list<Item>::iterator it = loot.begin(); it != loot.end(); ++it)
				{
					room->AddItem(*it);
				}
			}
			PC->AwardExperience(opponent.GetStats().GetExp());
			room->RemoveNpc(opponent.GetName());
			break;
		}
	}
	else
		cout << "That is not a valid target." << endl;
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

	fstream f();
	string sInput;
	int userInput; // Holds the key pressed by the user
	stringstream convertInput;
	while (true)
	{
		int i = -1;
		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			i++;
			if(PC->GetLevel() >= it->m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Ability " << i+1 << ": " << it->m_name << endl;
			}
		}
<<<<<<< HEAD
		cout << "Enter the number of the ability to see its full effects or 0 to quit: \n";
		getline(cin, sInput);
		convertInput.str("");
		convertInput.clear();
		convertInput.str(sInput);
		while (!(convertInput >> userInput))
		{
			convertInput.str("");
			convertInput.clear();
			cout << "Make sure to enter the NUMBER that is next to the ability you want to see: ";
			getline(cin, sInput);
			convertInput.str(sInput);
		}
=======
		cout << "Enter the number of the ability to see its full effects or 0 to quit: ";
		cin >> userInput;
		cin.clear();
>>>>>>> b84d2a70e74eef08e4e210a490d33f6a2f17d933
		cout << endl;
		userInput--;
		if (userInput == -1)
			break;
		if(PC->GetLevel() >= pcAbil[userInput].m_unlockLevel)// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		{
			cout << "Name: " << pcAbil[userInput].m_name << endl;
			cout << "Description: " << pcAbil[userInput].m_desc;
			cout << "Cool Down: " << pcAbil[userInput].m_cooldown << endl;
			cout << "HP Cost: " << pcAbil[userInput].m_hpCost << endl;
			cout << "MP Cost: " << pcAbil[userInput].m_mpCost << endl;
			cout << "Target: " << pcAbil[userInput].m_target << endl;
			cout << "Affects: " << pcAbil[userInput].m_type << endl;
			cout << "Amount: " << pcAbil[userInput].m_amount << endl;
		}
		else
		{
			cout << "That is not an unlocked ability." << endl;
		}
		cout << endl;
	}
}

void Help()
{
	cout << "If there are ' marks around a word, that means it is a command. You do not type in the ' marks around the command." << endl;
	cout << "'look' or 'l' will show you the contents of the room you are in." << endl;
	cout << "'north' or 'n' will move you north if it is a valid exit for the room you are in. The other directions have similar commands." << endl;
	cout << "'kill' or 'k' will attempt battle with an npc. Note this command requires a target. Ex: 'kill ogre' would attempt battle with the ogre in the room." << endl;
	cout << "'score' or 'sc' will show you your current stats." << endl;
	cout << "'abilities' or 'ab' will show you all of your current abilities and what they do." << endl;
}