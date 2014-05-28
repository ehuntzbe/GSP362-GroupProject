#pragma once
#include <unordered_map>
#include <string>
using namespace std;

//Created here for class usage, defined in Commands.cpp
enum command;

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