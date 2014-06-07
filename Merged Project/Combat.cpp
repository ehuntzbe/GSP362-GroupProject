// Eric H. 6/4
#include <string>
#include <iostream>
#include <cstdlib>
#include "Combat.h"
using namespace std;

combat_outcome Combat(Combatant player, Combatant enemy)
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
			getline(cin, userInput);
			if(	(userInput == "a") || (userInput == "attack") ||
				(userInput == "g") || (userInput == "guard") ||
				(userInput == "f") || (userInput == "flee")
				)
				valid = true;
		} while(valid == false);

		// attack
		if((userInput == "a") || (userInput == "attack")) {
			damage = ((player.GetStr()/2) + (rand() % (player.GetStr()/2))) - ((enemy.GetAs()/2) + (rand() % (enemy.GetAs()/2)));
			if(damage < 0)	damage = 0;
			hp = enemy.GetHp();
			hp = hp - damage;
			enemy.SetHp(hp);
		}

		// guard
		if((userInput == "g") || (userInput == "guard")) {
			player_guard = true;
		}

		// flee
		if((userInput == "f") || (userInput == "flee")) {
			if((player.GetAgi() > enemy.GetAgi()) && (rand() % 3 < 2))	return FLED;
		}

		// if enemy's hp is 0 or less, kill enemy and return true
		if(enemy.GetHp() <= 0) {
			return KILLED;
		}
		
		enemy_guard = false;

		// let enemy perform random attack on player
		int enemy_choice = rand() % 2;
		switch(enemy_choice) {
		case 0:
			// attack
			damage = ((enemy.GetStr()/2) + (rand() % (enemy.GetStr()/2))) - ((player.GetAs()/2) + (rand() % (player.GetAs()/2)));
			if(damage < 0)	damage = 0;
			
			hp = player.GetHp();
			hp = hp - damage;
			player.SetHp(hp);
			break;

		case 1:
			// guard
			enemy_guard = true;
			break;
		}

		// if player's hp is 0 or less, kill player and return false
		if(player.GetHp() <= 0) {
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
	return combinedStats;
}
