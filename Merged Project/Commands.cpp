#include "Commands.h"

CommandControl* CommandControl::m_commandInstance = NULL;

//Store all valid commands here - INVALID MUST BE THE FIRST COMMAND
enum command
{
	INVALID,
	LOOK,
	KILL,
	SCORE,

	//Directional commands
	NORTH,	SOUTH,	EAST,	WEST,	UP,	DOWN
};

//Store all command syntaxes here
CommandControl::CommandControl()
{
	AddCommandSyntax("k", KILL);
	AddCommandSyntax("kill", KILL);

	AddCommandSyntax("l", LOOK);
	AddCommandSyntax("look", LOOK);

	AddCommandSyntax("sc", SCORE);
	AddCommandSyntax("score", SCORE);

	AddCommandSyntax("n", NORTH);
	AddCommandSyntax("north", NORTH);

	AddCommandSyntax("s", SOUTH);
	AddCommandSyntax("south", SOUTH);

	AddCommandSyntax("e", EAST);
	AddCommandSyntax("east", EAST);

	AddCommandSyntax("w", WEST);
	AddCommandSyntax("west", WEST);

	AddCommandSyntax("u", UP);
	AddCommandSyntax("up", UP);

	AddCommandSyntax("d", DOWN);
	AddCommandSyntax("down", DOWN);
}

CommandControl* CommandControl::GetInstance()
{
	if (m_commandInstance == NULL)
	{
		m_commandInstance = new CommandControl();
	}
	return m_commandInstance;
}

bool CommandControl::IsValidSyntax(string p_in)
{
	return m_commandSyntax[p_in] != INVALID;
}