#include "Player.h"


int Player::GetExperience()
{
	return m_experience; 
}

//Function to increase the level of player and stats
int Player::GetLevel()
{	
	if( m_experience >= 100 )
	{
		//Increment the level by 1 when experience is greater than 100%
		m_level++;
		return m_level;
	}
}

int Player::GetStats()
{ 
	return m_stats; 
}

Room* Player::GetCurrentRoom()
{
	return m_currentRoom;
}
