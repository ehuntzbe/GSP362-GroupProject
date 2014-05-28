#include "Save and Load.h"

void Save(Character& playerChar)
{
	ofstream myfile ("PlayerCharacter.txt");
	if (myfile.is_open())
	{
		myfile << playerChar.GetName();
		myfile << "\n";
		myfile << playerChar.GetMaxHp();
		myfile << "\n";
		myfile << playerChar.GetMaxMp();
		myfile << "\n";
		myfile << playerChar.GetMaxStr();
		myfile << "\n";
		myfile << playerChar.GetMaxAgi();	
		myfile << "\n";
		myfile << playerChar.GetMaxAs();
		myfile << "\n";
		myfile << playerChar.GetHp();	
		myfile << "\n";
		myfile << playerChar.GetMp();	
		myfile << "\n";
		myfile << playerChar.GetStr();	
		myfile << "\n";
		myfile << playerChar.GetAgi();	
		myfile << "\n";
		myfile << playerChar.GetAs();
		myfile << "\n";
		myfile.close();

		cout << "Save Completed";
	}
	else cout << "Unable to open file Save fialed";
}

void Load(Character& playerChar)
{
	string m_line;
	int m_stat = 0;
	ifstream myfile ("PlayerCharacter.txt");
	if (myfile.is_open())
	{
		getline (myfile,m_line);
		if (m_line != "")
		{	
		playerChar.SetName(m_line);
		getline (myfile,m_line);
		playerChar.SetMaxHp(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetMaxMp(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetMaxStr(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetMaxAgi(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetMaxAs(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetHp(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetMp(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetStr(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetAgi(atoi(m_line.c_str()));
		getline (myfile,m_line);
		playerChar.SetAs(atoi(m_line.c_str()));

		cout <<  "Load Completed";

		}
		
		else
		{
			cout << "Unable to Load file";
		}

		myfile.close();
	}
	else cout << "Unable to open file Load failed"; 
}