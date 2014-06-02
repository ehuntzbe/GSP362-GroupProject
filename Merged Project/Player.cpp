#include "Player.h"

//Function to return the amount of experience the player has
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

//Function to reset experience to 0 and increase the amount you need to gain another level
int Player::GetExperience()
{
}

//Function to describe the ablities 
string Player::GetAbilites()
{
}

//Function for new abilites
string Player::GetAbilites()
{
}

//Function to return the value of stats
int Player::GetStats()
{ 
	return m_stats; 
}

//Function to get the current room of the player
Room* Player::GetCurrentRoom()
{
	return m_currentRoom;
}

void Player::SetCurrentRoom(Room* p_room)
{
	m_currentRoom = p_room;
}