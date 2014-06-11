#pragma once
#include <unordered_map>
#include <string>
using namespace std;

//Store all valid commands here - INVALID MUST BE THE FIRST COMMAND
enum command
{
	INVALID,
	LOOK,
	GET,
	DROP,
	EXAMINE,
	KILL,
	SCORE,
	INVENTORY,
	EQUIPMENT,
	WEAR,
	REMOVE,
	ABILITIES,
	HELP,
	GROWTH,
	QUIT,
	USE,

	//Directional commands
	GO_NORTH,	GO_SOUTH,	GO_EAST,	GO_WEST,	GO_UP,	GO_DOWN
};

/*
This class is a singleton. Access the only instance with CommandControl::GetInstance()
*/
class CommandControl
{
private:
	unordered_map<string, command> m_commandSyntax;
	//Constructor is private for singleton implementation
	CommandControl();
	~CommandControl();
	static CommandControl* m_commandInstance;
public:
	//Adds a command to the map
	void AddCommandSyntax(string p_in, command p_cmd){m_commandSyntax[p_in] = p_cmd;}
	//Tests if the string's value is INVALID (0) - if it is, this is an invalid command
	bool IsValidSyntax(string p_in);
	//Returns the command value of the input string
	command GetCommand(string p_in) {return m_commandSyntax[p_in];}
	//Access the instance of CommandControl
	static CommandControl* GetInstance();
};