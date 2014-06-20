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
		myfile << PC->GetCurrentRoom()->GetRoomId();
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
		myfile << PC->GetEqHp();
		myfile << "\n";
		myfile << PC->GetEqMp();
		myfile << "\n";
		myfile << PC->GetEqAgi();
		myfile << "\n";
		myfile << PC->GetEqStr();
		myfile << "\n";
		myfile << PC->GetEqAs();
		myfile.close();


		//ifstream myfile ("NPC.txt");
		ofstream savefile ("NPCload.txt");
		string line;

		if (savefile.is_open())
		{	
			for(int a = 0; a < World::GetInstance()->RoomCount(); a++)
			{
				if(World::GetInstance()->GetRooms()[a]->NpcList().size() > 0)
				{
					for(int b = 0; b < World::GetInstance()->GetRooms()[a]->NpcList().size(); b++)
					{
						if(World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetLife() == "")
						{
							World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetLife("A");
						}

						savefile << World::GetInstance()->GetRooms()[a]->GetNumNpc() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetLife() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetMaxHp() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetMaxMp() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetMaxStr() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetMaxAgi() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetMaxAs() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetHp() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetMp() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetStr() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetAgi() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetAs() << "\n";
						savefile << World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->GetExp() << "\n" << "\n";
					}
				}
			}
			
			savefile.close();
		}
		cout << endl << "Save Completed" << endl << endl;
	}
		else cout << "Unable to open file. Save failed.";
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
			PC->SetCurrentRoom(World::GetInstance()->GetRooms()[atoi(line.c_str())]);
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
			getline (myfile,line);
			temp.SetHp(temp.GetHp()-atoi(line.c_str())); //reduce the player's stats by the equipment boost so that it isn't doubled when items are loaded
			temp.SetMaxHp(temp.GetMaxHp()-atoi(line.c_str()));
			getline (myfile,line);
			temp.SetMp(temp.GetMp()-atoi(line.c_str()));
			temp.SetMaxMp(temp.GetMaxMp()-atoi(line.c_str()));
			getline (myfile,line);
			temp.SetAgi(temp.GetAgi()-atoi(line.c_str()));
			temp.SetMaxAgi(temp.GetMaxAgi()-atoi(line.c_str()));
			getline (myfile,line);
			temp.SetStr(temp.GetStr()-atoi(line.c_str()));
			temp.SetMaxStr(temp.GetMaxStr()-atoi(line.c_str()));
			getline (myfile,line);
			temp.SetAs(temp.GetAs()-atoi(line.c_str()));
			temp.SetMaxAs(temp.GetMaxAs()-atoi(line.c_str()));

			PC->SetStats(temp);
		}
	}
	else
		cout << "Unable to open load file. Load failed." << endl;
	myfile.close();

	ifstream loadfile ("NPCload.txt");
	line = "";

	if (loadfile.is_open())
	{	
		for(int a = 0; a < World::GetInstance()->RoomCount(); a++)
		{
			if(World::GetInstance()->GetRooms()[a]->NpcList().size() > 0)
			{
				for(int b = 0; b < World::GetInstance()->GetRooms()[a]->NpcList().size(); b++)
				{
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->SetNumNpc(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetLife(line);
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetMaxHp(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetMaxMp(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetMaxStr(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetMaxAgi(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetMaxAs(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetHp(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetMp(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetStr(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetAgi(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetAs(atoi(line.c_str()));
					getline(loadfile, line);
					World::GetInstance()->GetRooms()[a]->NpcList()[b].GetStats()->SetExp(atoi(line.c_str()));
				}
			}
		}
		cout << endl <<"Load Completed" << endl << endl;
		loadfile.close();
	}
	else
		cout << "Unable to Load file";
}