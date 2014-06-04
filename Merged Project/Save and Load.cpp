#include "Save and Load.h"

void Save(Player& playerChar)
{
	ofstream myfile ("PlayerCharacter.txt");
	if (myfile.is_open())
	{
		Combatant temp;
		temp = playerChar.GetStats();
		
		myfile << playerChar.GetName();
		myfile << "\n";
		myfile << temp.GetMaxHp();
		myfile << "\n";
		myfile << temp.GetMaxMp();
		myfile << "\n";
		myfile << temp.GetMaxStr();
		myfile << "\n";
		myfile << temp.GetMaxAgi();	
		myfile << "\n";
		myfile << temp.GetMaxAs();
		myfile << "\n";
		myfile << temp.GetHp();	
		myfile << "\n";
		myfile << temp.GetMp();	
		myfile << "\n";
		myfile << temp.GetStr();	
		myfile << "\n";
		myfile << temp.GetAgi();	
		myfile << "\n";
		myfile << temp.GetAs();
		myfile << "\n";
		myfile << temp.GetExp();
		myfile << "\n";
		myfile.close();

		cout << endl << "Save Completed" << endl << endl;
	}
	else cout << "Unable to open file Save fialed";
}

void Load(Player& playerChar)
{
	string m_line;
	int m_stat = 0;
	ifstream myfile ("PlayerCharacter.txt");
	if (myfile.is_open())
	{
		getline (myfile,m_line);
		if (m_line != "")
		{
			Combatant temp;
			
			playerChar.SetName(m_line);
			getline (myfile,m_line);
			temp.SetMaxHp(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetMaxMp(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetMaxStr(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetMaxAgi(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetMaxAs(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetHp(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetMp(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetStr(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetAgi(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetAs(atoi(m_line.c_str()));
			getline (myfile,m_line);
			temp.SetExp(atoi(m_line.c_str()));

			playerChar.SetStats(temp);

			cout << endl <<"Load Completed" << endl << endl;

		}

		else
		{
			cout << "Unable to Load file";
		}

		myfile.close();
	}
	else cout << "Unable to open file Load failed"; 
}