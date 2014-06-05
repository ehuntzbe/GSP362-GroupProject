#include "Interface.h"

Interface* Interface::m_interfaceInstance = NULL;

Interface::Interface()
{
	WORLD->LoadRoomsFromFile("WorldTest.txt", "NPC.txt");
}

Interface::~Interface()
{

}

Interface* Interface::GetInstance()
{
	if (m_interfaceInstance == NULL)
	{
		m_interfaceInstance = new Interface();
	}
	return m_interfaceInstance;
}

void Interface::MainGame()
{
	string input = "";
	vector<string> parsedInput;
	bool quitGame = false;
	while(!quitGame)
	{
		cout << ">";
		getline(cin, input);
		for (int i = 0; i < input.size(); i++)
			tolower(input[i]);
		parsedInput = ParseInput(input);
		command cmd = CommandControl::GetInstance()->GetCommand(parsedInput.front());
		string target = parsedInput.back();
		if (cmd == LOOK)
			Look();
		if (cmd == GO_NORTH)
			North();
		if (cmd == GO_SOUTH)
			South();
		if (cmd == GO_EAST)
			East();
		if (cmd == GO_WEST)
			West();
		if (cmd == GO_DOWN)
			Down();
		if (cmd == GO_UP)
			Up();
		if (cmd == KILL)
		{
			//Character* target = FindChar(parsedInput.back()); //Need a FindChar function that will check through the characters in the room and return the one that has the target the player gave
			//if(target != NULL))
			//	Kill(target);
		}
		if (cmd == SCORE)
			Score();
		if (cmd == ABILITIES)
			Abilities();
	}
}