#include <string>
#include <iostream>
#include <cstdlib>
#include "Combat.h"
using namespace std;

enum combat_outcome {DEAD=0, FLED, KILL};


int Combat(Combatant player, Combatant enemy)
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
			// attack formula for player:
			//		(R + s/2)*(m+1)

			// R = random number (ranging from 1 to 4)
			// s = strength
			// m = magic

			damage = ((rand() % 4 + 1) + player.GetStr()/2) * (1 + player.GetMp()/2);
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
			if(rand() % 3 == 0)	return FLED;
		}

		// if enemy's hp is 0 or less, kill enemy and return true
		if(enemy.GetHp() <= 0) {
			return KILL;
		}
		
		enemy_guard = false;

		// let enemy perform random attack on player
		int enemy_choice = rand() % 3;
		switch(enemy_choice) {
		case 0:
			// attack

			// attack formula for enemy:
			//		(R + s/2)*(m+1)

			// R = random number (ranging from 1 to 3)
			// s = strength
			// m = magic

			damage = ((rand() % 3 + 1) + player.GetStr()/2) * (1 + player.GetMp()/2);

			hp = player.GetHp();
			hp = hp - damage;
			player.SetHp(hp);
			break;

		case 1:
			// guard
			enemy_guard = true;
			break;

		case 2:
			// flee
			if(rand() % 4 == 0)	return FLED;
			break;
		}

		// if player's hp is 0 or less, kill player and return false
		if(player.GetHp() <= 0) {
			return DEAD;
		}
	}
}