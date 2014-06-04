#include "Player.h"

Player* Player::m_Player = NULL;

//Function to describe the ablities 
string Player::GetAbilites()
{
	return "No abilities yet.";
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

Player* Player::GetInstance()
{
	if (m_Player == NULL)
	{
		m_Player = new Player();
	}
	return m_Player;
}