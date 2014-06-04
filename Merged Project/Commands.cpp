#include "Commands.h"

CommandControl* CommandControl::m_commandInstance = NULL;



//Store all command syntaxes here
CommandControl::CommandControl()
{
	AddCommandSyntax("k", KILL);
	AddCommandSyntax("kill", KILL);

	AddCommandSyntax("l", LOOK);
	AddCommandSyntax("look", LOOK);

	AddCommandSyntax("sc", SCORE);
	AddCommandSyntax("score", SCORE);

	AddCommandSyntax("inv", INVENTORY);
	AddCommandSyntax("i", INVENTORY);
	AddCommandSyntax("inventory", INVENTORY);

	AddCommandSyntax("n", GO_NORTH);
	AddCommandSyntax("north", GO_NORTH);

	AddCommandSyntax("s", GO_SOUTH);
	AddCommandSyntax("south", GO_SOUTH);

	AddCommandSyntax("e", GO_EAST);
	AddCommandSyntax("east", GO_EAST);

	AddCommandSyntax("w", GO_WEST);
	AddCommandSyntax("west", GO_WEST);

	AddCommandSyntax("u", GO_UP);
	AddCommandSyntax("up", GO_UP);

	AddCommandSyntax("d", GO_DOWN);
	AddCommandSyntax("down", GO_DOWN);
}

CommandControl::~CommandControl()
{

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