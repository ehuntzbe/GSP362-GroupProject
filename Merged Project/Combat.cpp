#include <string>
#include <iostream>
#include "Combat.h"
using namespace std;

bool Combat(Combatant player, Combatant enemy);	// combat function prototype

bool Combat(Combatant player, Combatant enemy)
{	// Plays a combat.
	// Returns true if player defeats enemy, and false otherwise

	// set enemy hp
	enemy.SetMaxHp(10);
	enemy.SetHp(enemy.GetMaxHp());

	while(1)
	{
		// ask for command input from player, and execute it
		// TODO

		// let enemy perform random attack on player
		// TODO

		// if enemy's hp is 0 or less, kill enemy and return true
		if(enemy.GetHp() <= 0) {
			return true;
		}

		// if player's hp is 0 or less, kill player and return false
		if(player.GetHp() <= 0) {
			return false;
		}
	}
}