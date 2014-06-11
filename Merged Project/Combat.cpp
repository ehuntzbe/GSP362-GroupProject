// Eric H. 6/4
#include <string>
#include <iostream>
#include <cstdlib>
#include "Combat.h"
#include "Sound.h"
using namespace std;

combat_outcome Combat(Combatant *player, Combatant *enemy)
{	// Plays a combat.
	// Returns true if player defeats enemy, and false otherwise

	signed int damage = 0, hp = 0;
	bool player_guard = false, enemy_guard = false;
	bool valid = false;
	string userInput;

	while(1)
	{
		player_guard = false;
		valid = false;

		// ask for command input from player, and execute it
		do {
			cout << "Attack \tGuard \txxxxxxx \tFlee \n" //replace xxxxxxx with Ability when implemented
				"HP: " << player->GetHp() << "/" << player->GetMaxHp() << " | MP: " << player->GetMp() << "/" << player->GetMaxMp() << " |>" << endl;
			getline(cin, userInput);
			if(	(userInput == "a") || (userInput == "attack") ||
				(userInput == "g") || (userInput == "guard") ||
				(userInput == "f") || (userInput == "flee")
				)
				valid = true;
		} while(valid == false);

		// attack
		if((userInput == "a") || (userInput == "attack")) {
			damage = ((player->GetStr()/2) + (rand() % (player->GetStr()/2))) - ((enemy->GetAs()/2) + (rand() % (enemy->GetAs()/2)));
			if(damage < 0)	damage = 0;
			cout << "You hit the enemy for " << damage << " damage!" << endl;
			hp = enemy->GetHp();
			hp = hp - damage;
			enemy->SetHp(hp);
			SoundEffect(L"defaultjump.wav",L"Joke.wav");
		}

		// guard
		if((userInput == "g") || (userInput == "guard")) {
			player_guard = true;
			cout << "You put up your guard.." << endl;
			SoundEffect(L"defaultjump.wav",L"Joke.wav");
		}

		// flee
		if((userInput == "f") || (userInput == "flee")) {
			cout << "You attempt to flee." << endl;
			if(((player->GetAgi()/2) + (rand() % (player->GetAgi()/2))) - ((enemy->GetAgi()/2) + (rand() % (enemy->GetAgi()/2))) > 0)
			{
					return FLED;
					SoundEffect(L"defaultjump.wav",L"Joke.wav");
			}
			cout << "You couldn't get away!" << endl;
			SoundEffect(L"defaultjump.wav",L"Joke.wav");
		}

		// if enemy's hp is 0 or less, kill enemy and return true
		if(enemy->GetHp() <= 0) {
			cout << "You strike the finishing blow!" << endl;
			SoundEffect(L"defaultjump.wav",L"Joke.wav");
			return KILLED;
		}
		
		enemy_guard = false;

		// let enemy perform random attack on player
		int enemy_choice = rand() % 2;
		switch(enemy_choice) {
		case 0:
			// attack
			damage = ((enemy->GetStr()/2) + (rand() % (enemy->GetStr()/2))) - ((player->GetAs()/2) + (rand() % (player->GetAs()/2)));
			if(damage < 0)	damage = 0;
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
			cout << "A fatal low strikes you.." << endl;
			return DEAD;
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
