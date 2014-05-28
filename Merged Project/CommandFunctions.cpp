#include "CommandFunctions.h"

void Look()
{
	//get character's current room
	Room temp;
	cout << temp.GetName() << endl;
	cout << temp.GetDesc() << endl;
	cout << "EXITS:"; temp.DisplayExits(); cout << endl;
}

void Kill(Character p_target)
{
	//check if character is killable
	//Combat(player.stats, p_target.stats);
}

void North()
{
	//set player's current room to current room->north
	Look();
}

void South()
{

}

void East()
{

}

void West()
{

}

void Up()
{

}

void Down()
{

}

void Score()
{
	//Output score screen
}