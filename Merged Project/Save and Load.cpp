#include "Save and Load.h"

void Save()
{
	ofstream myfile ("PlayerCharacter.txt");
	if (myfile.is_open())
	{
		Combatant *temp;
		temp = PC->GetStats();
		temp->SetExp(PC->GetExperience());
		
		myfile << PC->GetName();
		myfile << "\n";
		myfile << PC->GetDesc();
		myfile << "\n";
		myfile << PC->GetLevel();
		myfile << "\n";
		myfile << PC->GetPrimeStat();
		myfile << "\n";
		myfile << PC->GetSecondStat();
		myfile << "\n";
		myfile << PC->GetCurrentRoom()->GetName();
		myfile << "\n";
		myfile << temp->GetMaxHp();
		myfile << "\n";
		myfile << temp->GetMaxMp();
		myfile << "\n";
		myfile << temp->GetMaxStr();
		myfile << "\n";
		myfile << temp->GetMaxAgi();	
		myfile << "\n";
		myfile << temp->GetMaxAs();
		myfile << "\n";
		myfile << temp->GetHp();	
		myfile << "\n";
		myfile << temp->GetMp();	
		myfile << "\n";
		myfile << temp->GetStr();	
		myfile << "\n";
		myfile << temp->GetAgi();	
		myfile << "\n";
		myfile << temp->GetAs();
		myfile << "\n";
		myfile << temp->GetExp();
		myfile << "\n";
		myfile.close();

		cout << endl << "Save Completed" << endl << endl;
	}
	else cout << "Unable to open file Save fialed";
}

void Load()
{
	string line;
	ifstream myfile ("PlayerCharacter.txt");
	if (myfile.is_open())
	{
		getline (myfile,line);
		if (line != "")
		{
			Combatant temp;
			int roomNum = 0;
						
			PC->SetName(line);
			getline (myfile,line);
			PC->SetDesc(line);
			getline (myfile,line);
			PC->SetLevel(atoi(line.c_str()));
			getline (myfile,line);
			PC->SetPrimeStat(line);
			getline (myfile,line);
			PC->SetSecondStat(line);
			getline (myfile,line);

			for (int a = 0; a < World::GetInstance()->RoomCount(); a++)
			{
				if(line == World::GetInstance()->GetRooms()[a]->GetName())
				{
					roomNum = a;
					break;
				}
			}

			PC->SetCurrentRoom(World::GetInstance()->GetRooms()[roomNum]);
			getline (myfile,line);
			temp.SetMaxHp(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetMaxMp(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetMaxStr(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetMaxAgi(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetMaxAs(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetHp(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetMp(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetStr(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetAgi(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetAs(atoi(line.c_str()));
			getline (myfile,line);
			temp.SetExp(atoi(line.c_str()));

			PC->SetStats(temp);

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