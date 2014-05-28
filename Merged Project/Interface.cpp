#include "Interface.h"

Interface* Interface::m_interfaceInstance = NULL;

Interface::Interface()
{

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
		if (parsedInput.front() == "look")
			Look();
		if (parsedInput.front() == "north")
			North();
		if (parsedInput.front() == "south")
			South();
		if (parsedInput.front() == "east")
			East();
		if (parsedInput.front() == "west")
			West();
		if (parsedInput.front() == "down")
			Down();
		if (parsedInput.front() == "up")
			Up();
		if (parsedInput.front() == "kill")
		{
			//Character* target = FindChar(parsedInput.back()); //Need a FindChar function that will check through the characters in the room and return the one that has the target the player gave
			//if(target != NULL))
			//	Kill(target);
		}
		if (parsedInput.front() == "score")
			Score();
	}
}