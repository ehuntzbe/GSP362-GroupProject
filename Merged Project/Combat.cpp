// Eric H. 6/4
#include <string>
#include <iostream>
#include <cstdlib>
#include "Combat.h"
#include "Sound.h"
#include "InputParsing.h"
#include "Abilities.h"
#include "Commands.h"
#include <sstream>
using namespace std;

unordered_map<string, int> cooldowns;

ability ChooseAbility()
{
	vector<ability> pcAbil = PC->GetAbilities();
	string sInput;
	int userInput; // Holds the key pressed by the user
	stringstream convertInput;
	while (true)
	{
		int i = -1;
		for (vector<ability>::iterator it = pcAbil.begin();	it != pcAbil.end();	++it)
		{
			i++;
			if(it->IsUnlocked())// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
			{
				cout << "Ability " << i+1 << ": " << it->m_name << endl;
			}
		}
		cout << "Enter the number of the ability to see its full effects or 0 to go back: ";
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
		cout << endl;
		userInput--;
		if (userInput == -1)
			break;
		if(pcAbil[userInput].IsUnlocked())// if PC->GetLevel() is greater than or equal to it->m_unlockedLevel
		{
			int cd = cooldowns[pcAbil[userInput].m_name];
			cout << "Name: " << pcAbil[userInput].m_name << endl;
			cout << "Description: " << pcAbil[userInput].m_desc;
			cout << "Cool Down: " << pcAbil[userInput].m_cooldown << endl;
			cout << "Cool Down Remaining: " << cd << endl;
			cout << "HP Cost: " << pcAbil[userInput].m_hpCost << endl;
			cout << "MP Cost: " << pcAbil[userInput].m_mpCost << endl;
			cout << "Target: " << pcAbil[userInput].m_target << endl;
			cout << "Affects: " << pcAbil[userInput].GetType() << endl;
			cout << "Amount: " << pcAbil[userInput].m_amount << endl;
			if (cd == 0)
			{
				cout << "Use this ability? (y/n): ";
				getline(cin, sInput);
				sInput[0] = tolower(sInput[0]);
				if (sInput == "y")
				{
					cooldowns[pcAbil[userInput].m_name] = pcAbil[userInput].m_cooldown;
					return pcAbil[userInput];
				}
			}
			else
				cout << "This ability is on cool down." << endl;
		}
		else
		{
			cout << "That is not an unlocked ability." << endl;
		}
		cout << endl;
	}
	ability blankAb;
	return blankAb;
}

combat_outcome Combat(Combatant *player, Combatant *enemy)
{	// Plays a combat.
	// Returns true if player defeats enemy, and false otherwise

	signed int damage = 0, hp = 0;
	bool player_guard = false, enemy_guard = false;
	bool valid = true;
	string userInput;
	vector<string> parsedInput;
	command cmd;
	for (unordered_map<string, int>::iterator it = cooldowns.begin(); it != cooldowns.end(); ++it)
	{
		it->second = 0;
	}

	while(1)
	{
		player_guard = false;
		valid = true;
		for (unordered_map<string, int>::iterator it = cooldowns.begin(); it != cooldowns.end(); ++it)
		{
			if (it->second != 0)
				it->second--;
		}
		// ask for command input from player, and execute it
		do
		{
			cout << "Attack \tGuard \tAbilities \tFlee \n"
				"HP: " << player->GetHp() << "/" << player->GetMaxHp() << " | MP: " << player->GetMp() << "/" << player->GetMaxMp() << " |>" << endl;
			getline(cin, userInput);
			for (int i = 0; i < userInput.size(); i++)
				userInput[i] = tolower(userInput[i]);
			parsedInput = ParseInput(userInput);
			cmd = CommandControl::GetInstance()->GetCommand(parsedInput.front());
		} while(cmd != ATTACK && cmd != GUARD && cmd != FLEE && cmd != ABILITIES);

		// attack
		switch(cmd)
		{
		case ATTACK:
			damage = ((player->GetStr()/2) + (rand() % (player->GetStr()/2))) - ((enemy->GetAs()/2) + (rand() % (enemy->GetAs()/2)));
			if (enemy_guard == true && damage != 0)
				damage /= 2;
			if(damage < 0)
				damage = 0;
			cout << "You hit the enemy for " << damage << " damage!" << endl;
			hp = enemy->GetHp();
			hp = hp - damage;
			enemy->SetHp(hp);
			break;
		case GUARD:
			player_guard = true;
			cout << "You put up your guard.." << endl;
			break;
		case FLEE:
			cout << "You attempt to flee." << endl;
			if(((player->GetAgi()/2) + (rand() % (player->GetAgi()/2))) - ((enemy->GetAgi()/2) + (rand() % (enemy->GetAgi()/2))) > 0)
			{
					return FLED;
			}
			cout << "You couldn't get away!" << endl;
			break;
		case ABILITIES:
			ability::UpdateAbilities();
			ability choice = ChooseAbility();
			if (choice.m_name != "none")
			{
				player->SetHp(player->GetHp() - choice.m_hpCost);
				player->SetMp(player->GetMp() - choice.m_mpCost);
				Combatant* target;
				if (choice.m_target == SELF)
				{
					target = player;
					cout << "Your ";
				}
				else
				{
					target = enemy;
					cout << "The enemy's ";
				}
				switch(choice.m_type)
				{
				case HP:
					target->SetHp(target->GetHp() + choice.m_amount);
					cout << "HP is ";
					break;
				case MP:
					target->SetMp(target->GetMp() + choice.m_amount);
					cout << "MP is ";
					break;
				case AS:
					target->SetAs(target->GetAs() + choice.m_amount);
					cout << "AS is ";
					break;
				case AGI:
					target->SetAgi(target->GetAgi() + choice.m_amount);
					cout << "AGI is ";
					break;
				case STR:
					target->SetStr(target->GetStr() + choice.m_amount);
					cout << "STR is ";
					break;
				}
				if (choice.m_amount > 0)
					cout << "restored by " << choice.m_amount << "." << endl;
				else
					cout << "damaged by " << -choice.m_amount << "." << endl;
			}
			else
				valid = false;
			break;
		}
		if (player->GetHp() > player->GetMaxHp())
			player->SetHp(player->GetMaxHp());
		if (player->GetMp() > player->GetMaxMp())
			player->SetMp(player->GetMaxMp());
		// if enemy's hp is 0 or less, kill enemy and return true
		if(enemy->GetHp() <= 0) {
			cout << "You strike the finishing blow!" << endl;
			return KILLED;
		}
		if (valid == true)
		{
			enemy_guard = false;
			// let enemy perform random attack on player
			int enemy_choice = rand() % 2;
			switch(enemy_choice)
			{
			case 0:
				// attack
				damage = ((enemy->GetStr()/2) + (rand() % (enemy->GetStr()/2))) - ((player->GetAs()/2) + (rand() % (player->GetAs()/2)));
				if (player_guard == true && damage != 0)
					damage /= 2;
				if(damage < 0)
					damage = 0;
				cout << "The enemy hits you for " << damage << " damage!" << endl;
				hp = player->GetHp();
				hp = hp - damage;
				player->SetHp(hp);
				break;

			case 1:
				// guard
				cout << "The enemy puts up their guard.." << endl;
				enemy_guard = true;
				break;
			}

			// if player's hp is 0 or less, kill player and return false
			if(player->GetHp() <= 0) {
				cout << "A fatal blow strikes you.." << endl;
				return DEAD;
			}
		}
	}
}

Combatant Combatant::operator+(Combatant p_other)
{
	Combatant combinedStats;
	combinedStats.m_currentAgi = m_currentAgi + p_other.m_currentAgi;
	combinedStats.m_currentAs = m_currentAs + p_other.m_currentAs;
	combinedStats.m_currentStr = m_currentStr + p_other.m_currentStr;
	combinedStats.m_currentHp = m_currentHp + p_other.m_currentHp;
	combinedStats.m_currentMp = m_currentMp + p_other.m_currentMp;
	combinedStats.m_maxAgi = m_maxAgi + p_other.m_maxAgi;
	combinedStats.m_maxAs = m_maxAs + p_other.m_maxAs;
	combinedStats.m_maxStr = m_maxStr + p_other.m_maxStr;
	combinedStats.m_maxHp = m_maxHp + p_other.m_maxHp;
	combinedStats.m_maxMp = m_maxMp + p_other.m_maxMp;
	return combinedStats;
}
