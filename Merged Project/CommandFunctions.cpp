#include "CommandFunctions.h"

void Look()
{
	//get character's current room
	Room temp;
	cout << temp.GetName() << endl;
	cout << temp.GetDesc() << endl;
	cout << "EXITS:"; temp.DisplayExits(); cout << endl;
}

void Kill(Character* p_target)
{
	if (PC->GetCurrentRoom()->GetNPC(p_target->GetName()).GetName() != "NULL")
		Combat(PC->GetStats(), p_target->GetStats());
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
}

void Inventory()
{
	PC->DisplayInventory();
}