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

void Interface::Prompt()
{
	cout << "HP: " << PC->GetStats().GetHp() << "/" << PC->GetStats().GetMaxHp() << " | MP: " << PC->GetStats().GetMp() << "/" << PC->GetStats().GetMaxMp() << " |> ";
}

void Interface::MainGame()
{
	string input = "";
	vector<string> parsedInput;
	bool quitGame = false;
	Look();
	cout << "Type 'help' (no ' marks) for a short explanation of basic commands." << endl;
	cout << "Make sure to use the 'growth' commad before gaining experience!" << endl;
	while(!quitGame)
	{
		Prompt();
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
			Kill(parsedInput.back());
		if (cmd == SCORE)
			Score();
		if (cmd == ABILITIES)
			Abilities();
		if (cmd == HELP)
			Help();
		if (cmd == GROWTH)
			Growth();
	}
}
