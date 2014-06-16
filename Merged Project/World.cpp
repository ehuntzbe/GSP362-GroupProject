//Ashton 6/6/2014 9:07 PM
#include "World.h"

World* World::m_instance = NULL;

World::World()
{
	m_world = NULL;
}

World* World::GetInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new World();
	}
	return m_instance;
}

bool World::NS(Room* p_n, Room* p_s)
{
	return p_n->S(p_s) == true && p_s->N(p_n) == true;
}

bool World::WE(Room* p_w, Room* p_e)
{
	return p_w->E(p_e) == true && p_e->W(p_w) == true;
}

bool World::UD(Room* p_u, Room* p_d)
{
	return p_u->D(p_d) == true && p_d->U(p_u) == true;
}

//This function is outdated, but will not be deleted due to its potential ability to help in testing.
void World::DisplayRoom(int p_roomID)
{
	cout << endl;
	if (DISPLAY_ROOM_ID)
		cout << "ID: " << p_roomID << endl;
	cout << m_world[p_roomID]->GetName() << endl;
	cout << m_world[p_roomID]->GetDesc() << endl;	
	if(m_world[p_roomID]->GetNumNpc() > 0)
	{
		cout << m_world[p_roomID]->GetNumNpc() << endl;
		for (int a = 0; a < m_world[p_roomID]->GetNumNpc(); a++)
		{
			vector<Character> temp;
			Combatant* tempStats;
						
			temp = m_world[p_roomID]->NpcList();
			tempStats = temp[a].GetStats();

			cout << "Name: "<< temp[a].GetName() <<endl;
			cout << "Desc: "<< temp[a].GetDesc() <<endl;
			cout << "Max HP: "<< tempStats->GetMaxHp() <<endl;		
			cout << "Max MP: "<< tempStats->GetMaxMp() <<endl;		
			cout << "Max Str: "<< tempStats->GetMaxStr() <<endl;		
			cout << "Max Agi: "<< tempStats->GetMaxAgi() <<endl;		
			cout << "Max As: "<< tempStats->GetMaxAs() <<endl;		
			cout << "HP: "<< tempStats->GetHp() <<endl;			
			cout << "MP: "<< tempStats->GetMp() <<endl;			
			cout << "Str: "<< tempStats->GetStr() <<endl;			
			cout << "Agi: "<< tempStats->GetAgi() <<endl;			
			cout << "As: "<< tempStats->GetAs() <<endl;
			cout << "EXP: "<< tempStats->GetExp() <<endl;
		}
	}
	cout << "EXITS:"; m_world[p_roomID]->DisplayExits(); cout << endl;
}

void World::LoadNpcsFromFile(string p_npcFileName, Room* p_room)
{
	//test->NpcResize(test->GetNumNpc());
	ifstream myfile (p_npcFileName);
	string line;
	int tempcount = 0;
	int t_npcCount = 0;

	if (myfile.is_open())
	{
		//getline (myfile,line);
		while ( getline (myfile,line) )
		{
			if(line == p_room->GetName())
			{
				for(int a = 0; a < p_room->GetNumNpc(); a++)
				{
					Character m_npc;
					Combatant temp;

					getline (myfile,line);
					if(line == "")
					{
						getline (myfile,line);
					}
					m_npc.SetName(line);
					getline (myfile,line);
					m_npc.SetDesc(line);
					getline (myfile,line);
					m_npc.SetLife(line);
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

					if(m_npc.GetLife() == "A")
					{
						m_npc.SetStats(temp);

						p_room->NpcAdd(m_npc);
					}

					else
					{
						t_npcCount++;
					}

					tempcount++;
				}
			}

			/*else
			{
			cout << "Unable to Load file";
			}*/
			if(tempcount == p_room->GetNumNpc())
			{
				int tempNumNpc = 0;
				tempNumNpc = p_room->GetNumNpc() - t_npcCount;
				string npcLine = static_cast<ostringstream*>( &(ostringstream() << tempNumNpc) )->str();
				p_room->SetNumNpc(npcLine);
				myfile.close();
			}
		}
	}
	else cout << "Unable to open file Load failed"; 
}

vector<string> World::ParseDescription(string p_desc)
{
	vector<string> description;
	string buf = "";
	for (int i = 0; i < p_desc.size(); i++)
	{
		if (p_desc[i] == '\\' && p_desc[i+1] == 'n')
		{
			description.push_back(buf);
			i+=2;
			buf = "";
		}
		else
			buf += p_desc[i];
	}
	description.push_back(buf);
	return description;
}

void World::LoadRoomsFromFile(string p_fileName, string p_npcFileName)
{
	int counter = -1;
	string line;
	ifstream myfile (p_fileName);

	if (myfile.is_open())
	{
		getline (myfile,line);
		m_roomCount = atoi(line.c_str());
		m_world = new Room*[m_roomCount];

		for (int i = 0; i < m_roomCount; i++)
			m_world[i] = new Room();

		while ( getline (myfile,line) )
		{
			if(line == "")
			{
				counter++;
			}
			else
			{
				m_world[counter]->SetName(line);
				getline (myfile, line);
				vector<string> desc = ParseDescription(line);
				string parsedDesc = "";
				for (int i = 0; i < desc.size(); i++)
				{
					parsedDesc += desc[i];
					parsedDesc += "\n";
				}
				m_world[counter]->SetDesc(parsedDesc);
				getline (myfile, line);
				m_world[counter]->SetNumNpc(line);

				if(m_world[counter]->GetNumNpc() > 0)
				{
					LoadNpcsFromFile(p_npcFileName, m_world[counter]);
				}
			}
		}
		myfile.close();
	}
	else
		cout << "Unable to open file" << '\n';
	//Load rooms into the world
	ConnectRooms();
}

void World::ConfirmConnection(bool p_connection)
{
	if (p_connection == false)
	{
		cout << "GRAPH CONNECTION HAS FAILED. AN ATTEMPT TO LINK ONE EXIT TO MULTIPLE ROOMS HAS BEEN MADE." << endl;
		system("pause");
		exit(NULL);
	}
}

void World::ConnectRooms()
{
	//A1 & Map 1
	PC->SetCurrentRoom(m_world[1]);
	//A2
	ConfirmConnection(m_world[1]->N(m_world[2]));
	ConfirmConnection(m_world[2]->S(m_world[1]));
	//A3
	ConfirmConnection(m_world[2]->N(m_world[3]));
	ConfirmConnection(m_world[3]->N(m_world[7]));
	ConfirmConnection(m_world[3]->W(m_world[4]));
	ConfirmConnection(m_world[3]->S(m_world[2]));
	//B1
	ConfirmConnection(m_world[4]->W(m_world[5]));
	ConfirmConnection(m_world[4]->E(m_world[3]));
	//B2
	ConfirmConnection(m_world[5]->E(m_world[4]));
	//B3
	ConfirmConnection(NS(m_world[6], m_world[5]));
	//A4
	ConfirmConnection(m_world[7]->N(m_world[8]));
	ConfirmConnection(m_world[7]->S(m_world[3]));
	//A5
	ConfirmConnection(m_world[8]->N(m_world[9]));
	ConfirmConnection(m_world[8]->S(m_world[7]));
	//A6
	ConfirmConnection(m_world[9]->N(m_world[10]));
	ConfirmConnection(m_world[9]->S(m_world[8]));
	//Map 2
	//A1
	ConfirmConnection(m_world[10]->N(m_world[11]));
	ConfirmConnection(m_world[10]->S(m_world[9]));
	//A2
	ConfirmConnection(m_world[11]->N(m_world[12]));
	ConfirmConnection(m_world[11]->W(m_world[13]));
	ConfirmConnection(m_world[11]->S(m_world[10]));
	//B1
	ConfirmConnection(m_world[12]->S(m_world[11]));
	//A3
	ConfirmConnection(m_world[13]->W(m_world[14]));
	ConfirmConnection(m_world[13]->E(m_world[11]));
	//A4
	ConfirmConnection(m_world[14]->W(m_world[15]));
	ConfirmConnection(m_world[14]->E(m_world[13]));
	//A5
	ConfirmConnection(m_world[15]->W(m_world[16]));
	ConfirmConnection(m_world[15]->E(m_world[14]));
	//A6
	ConfirmConnection(m_world[16]->N(m_world[17]));
	ConfirmConnection(m_world[16]->E(m_world[15]));
	//A7
	ConfirmConnection(m_world[17]->N(m_world[18]));
	ConfirmConnection(m_world[17]->S(m_world[16]));
	//A8
	ConfirmConnection(m_world[18]->N(m_world[19]));
	ConfirmConnection(m_world[18]->S(m_world[17]));
	//A9
	ConfirmConnection(m_world[19]->N(m_world[20]));
	ConfirmConnection(m_world[19]->S(m_world[18]));
	//A10
	ConfirmConnection(m_world[20]->N(m_world[21]));
	ConfirmConnection(m_world[20]->S(m_world[19]));
	//A11
	ConfirmConnection(m_world[21]->N(m_world[22]));
	ConfirmConnection(m_world[21]->S(m_world[20]));
	//Map 3
	//A1
	ConfirmConnection(m_world[22]->N(m_world[23]));
	ConfirmConnection(m_world[22]->S(m_world[21]));
	//A2
	ConfirmConnection(m_world[23]->N(m_world[24]));
	ConfirmConnection(m_world[23]->S(m_world[22]));
	//A3
	ConfirmConnection(m_world[24]->N(m_world[25]));
	ConfirmConnection(m_world[24]->S(m_world[23]));
	//A4
	ConfirmConnection(m_world[25]->W(m_world[26]));
	ConfirmConnection(m_world[25]->N(m_world[28]));
	ConfirmConnection(m_world[25]->S(m_world[24]));
	//B1
	ConfirmConnection(m_world[26]->W(m_world[27]));
	ConfirmConnection(m_world[26]->E(m_world[25]));
	//Inn
	ConfirmConnection(m_world[27]->E(m_world[26]));
	//A5
	ConfirmConnection(m_world[28]->N(m_world[29]));
	ConfirmConnection(m_world[28]->S(m_world[25]));
	//A6
	ConfirmConnection(m_world[29]->N(m_world[30]));
	ConfirmConnection(m_world[29]->S(m_world[28]));
	//Map 4
	//A1
	ConfirmConnection(m_world[30]->N(m_world[31]));
	ConfirmConnection(m_world[30]->S(m_world[29]));
	//A2
	ConfirmConnection(m_world[31]->N(m_world[32]));
	ConfirmConnection(m_world[31]->S(m_world[30]));
	//A3
	ConfirmConnection(m_world[32]->W(m_world[33]));
	ConfirmConnection(m_world[32]->S(m_world[31]));
	//A4
	ConfirmConnection(m_world[33]->W(m_world[34]));
	ConfirmConnection(m_world[33]->E(m_world[32]));
	//A5
	ConfirmConnection(m_world[34]->W(m_world[37]));
	ConfirmConnection(m_world[34]->E(m_world[33]));
	ConfirmConnection(m_world[34]->S(m_world[35]));
	//B1
	ConfirmConnection(m_world[35]->S(m_world[36]));
	ConfirmConnection(m_world[35]->N(m_world[34]));
	//B2
	ConfirmConnection(m_world[36]->N(m_world[35]));
	//A6
	ConfirmConnection(m_world[37]->E(m_world[34]));
	ConfirmConnection(m_world[37]->N(m_world[38]));
	//A7
	ConfirmConnection(m_world[38]->N(m_world[39]));
	ConfirmConnection(m_world[38]->S(m_world[37]));
	//A8
	ConfirmConnection(m_world[39]->N(m_world[40]));
	ConfirmConnection(m_world[39]->S(m_world[38]));
	//A9
	ConfirmConnection(m_world[40]->W(m_world[41]));
	ConfirmConnection(m_world[40]->E(m_world[42]));
	ConfirmConnection(m_world[40]->S(m_world[39]));
	//B3
	ConfirmConnection(m_world[41]->E(m_world[40]));
	//A10
	ConfirmConnection(m_world[42]->E(m_world[43]));
	ConfirmConnection(m_world[42]->W(m_world[40]));
	//A11
	ConfirmConnection(m_world[43]->N(m_world[44]));
	ConfirmConnection(m_world[43]->W(m_world[42]));
	//A12
	ConfirmConnection(m_world[44]->N(m_world[45]));
	ConfirmConnection(m_world[44]->S(m_world[43]));
	//Map 5
	//A1
	ConfirmConnection(m_world[45]->N(m_world[46]));
	ConfirmConnection(m_world[45]->S(m_world[44]));
	//A2
	ConfirmConnection(m_world[46]->N(m_world[47]));
	ConfirmConnection(m_world[46]->S(m_world[45]));
	//A3
	ConfirmConnection(m_world[47]->N(m_world[52]));
	ConfirmConnection(m_world[47]->S(m_world[46]));
	ConfirmConnection(m_world[47]->W(m_world[48]));
	ConfirmConnection(m_world[47]->E(m_world[50]));
	//B1
	ConfirmConnection(m_world[48]->E(m_world[49]));
	ConfirmConnection(m_world[48]->W(m_world[47]));
	//B2
	ConfirmConnection(m_world[49]->N(m_world[48]));
	//C1
	ConfirmConnection(m_world[50]->E(m_world[51]));
	ConfirmConnection(m_world[50]->W(m_world[47]));
	//C2
	ConfirmConnection(m_world[51]->W(m_world[50]));
	//A4
	ConfirmConnection(m_world[52]->N(m_world[53]));
	ConfirmConnection(m_world[52]->S(m_world[47]));
	//A5
	ConfirmConnection(m_world[53]->N(m_world[54]));
	ConfirmConnection(m_world[53]->S(m_world[52]));
	//A6
	ConfirmConnection(m_world[54]->N(m_world[55]));
	ConfirmConnection(m_world[54]->S(m_world[53]));
	//A7
	ConfirmConnection(m_world[55]->N(m_world[56]));
	ConfirmConnection(m_world[55]->S(m_world[54]));
	//Map 6
	//A1
	ConfirmConnection(m_world[56]->N(m_world[57]));
	ConfirmConnection(m_world[56]->S(m_world[55]));
	//A2
	ConfirmConnection(m_world[57]->N(m_world[72]));
	ConfirmConnection(m_world[57]->S(m_world[55]));
	ConfirmConnection(m_world[57]->E(m_world[67]));
	ConfirmConnection(m_world[57]->W(m_world[58]));
	//B1
	ConfirmConnection(m_world[58]->E(m_world[57]));
	ConfirmConnection(m_world[58]->W(m_world[59]));
	//B2
	ConfirmConnection(m_world[59]->E(m_world[58]));
	ConfirmConnection(m_world[59]->W(m_world[60]));
	//B3
	ConfirmConnection(m_world[60]->N(m_world[61]));
	ConfirmConnection(m_world[60]->E(m_world[59]));
	//B4
	ConfirmConnection(m_world[61]->N(m_world[62]));
	ConfirmConnection(m_world[61]->S(m_world[60]));
	//B5
	ConfirmConnection(m_world[62]->N(m_world[63]));
	ConfirmConnection(m_world[62]->S(m_world[61]));
	//B6
	ConfirmConnection(m_world[63]->N(m_world[64]));
	ConfirmConnection(m_world[63]->S(m_world[62]));
	//B7
	ConfirmConnection(m_world[64]->E(m_world[65]));
	ConfirmConnection(m_world[64]->S(m_world[63]));
	//B8
	ConfirmConnection(m_world[65]->E(m_world[66]));
	ConfirmConnection(m_world[65]->W(m_world[64]));
	//B9
	ConfirmConnection(m_world[66]->E(m_world[75]));
	ConfirmConnection(m_world[66]->W(m_world[65]));
	//C1
	ConfirmConnection(m_world[67]->E(m_world[68]));
	ConfirmConnection(m_world[67]->W(m_world[57]));
	//C2
	ConfirmConnection(m_world[68]->N(m_world[69]));
	ConfirmConnection(m_world[68]->W(m_world[67]));
	//C3
	ConfirmConnection(m_world[69]->N(m_world[70]));
	ConfirmConnection(m_world[69]->S(m_world[68]));
	//C4
	ConfirmConnection(m_world[70]->W(m_world[71]));
	ConfirmConnection(m_world[70]->S(m_world[69]));
	//C5
	ConfirmConnection(m_world[71]->W(m_world[73]));
	ConfirmConnection(m_world[71]->E(m_world[70]));
	//A3
	ConfirmConnection(m_world[72]->N(m_world[73]));
	ConfirmConnection(m_world[72]->S(m_world[57]));
	//A4
	ConfirmConnection(m_world[73]->N(m_world[74]));
	ConfirmConnection(m_world[73]->S(m_world[72]));
	ConfirmConnection(m_world[73]->E(m_world[71]));
	//A5
	ConfirmConnection(m_world[74]->N(m_world[75]));
	ConfirmConnection(m_world[74]->S(m_world[73]));
	//A6
	ConfirmConnection(m_world[75]->N(m_world[76]));
	ConfirmConnection(m_world[75]->S(m_world[74]));
	ConfirmConnection(m_world[75]->W(m_world[71]));
	//A7/Inn
	ConfirmConnection(m_world[76]->E(m_world[77]));
	ConfirmConnection(m_world[76]->S(m_world[75]));
	//A8
	ConfirmConnection(m_world[77]->E(m_world[78]));
	ConfirmConnection(m_world[77]->W(m_world[76]));
	//A9
	ConfirmConnection(m_world[78]->E(m_world[79]));
	ConfirmConnection(m_world[78]->W(m_world[77]));
	//A10
	ConfirmConnection(m_world[79]->E(m_world[80]));
	ConfirmConnection(m_world[79]->W(m_world[78]));
	//A11
	ConfirmConnection(m_world[80]->N(m_world[81]));
	ConfirmConnection(m_world[80]->W(m_world[79]));
	//Map 7
	//A1
	ConfirmConnection(m_world[81]->N(m_world[82]));
	ConfirmConnection(m_world[81]->S(m_world[80]));
	//A2
	ConfirmConnection(m_world[82]->N(m_world[83]));
	ConfirmConnection(m_world[82]->S(m_world[81]));
	//A3
	ConfirmConnection(m_world[83]->N(m_world[84]));
	ConfirmConnection(m_world[83]->S(m_world[82]));
	//A4
	ConfirmConnection(m_world[84]->N(m_world[85]));
	ConfirmConnection(m_world[84]->S(m_world[83]));
	//A5
	ConfirmConnection(m_world[85]->E(m_world[86]));
	ConfirmConnection(m_world[85]->S(m_world[84]));
	ConfirmConnection(m_world[86]->E(m_world[87]));
	ConfirmConnection(m_world[86]->W(m_world[85]));
	//Inn1
	ConfirmConnection(m_world[87]->E(m_world[88]));
	ConfirmConnection(m_world[87]->W(m_world[86]));
	//Inn2
	ConfirmConnection(m_world[88]->N(m_world[89]));
	ConfirmConnection(m_world[88]->W(m_world[87]));
	//Inn3
	ConfirmConnection(m_world[89]->N(m_world[90]));
	ConfirmConnection(m_world[89]->S(m_world[88]));
	//Inn4
	ConfirmConnection(m_world[90]->W(m_world[91]));
	ConfirmConnection(m_world[90]->S(m_world[89]));
	//A6
	ConfirmConnection(m_world[91]->N(m_world[92]));
	ConfirmConnection(m_world[91]->E(m_world[90]));
	//Map 8
	//A1
	ConfirmConnection(m_world[92]->N(m_world[93]));
	ConfirmConnection(m_world[92]->S(m_world[91]));
	//A2
	ConfirmConnection(m_world[93]->W(m_world[94]));
	ConfirmConnection(m_world[93]->S(m_world[91]));
	//A3
	ConfirmConnection(m_world[94]->N(m_world[95]));
	ConfirmConnection(m_world[94]->E(m_world[93]));
	ConfirmConnection(m_world[94]->W(m_world[96]));
	//B1
	ConfirmConnection(m_world[95]->S(m_world[94]));
	//A4
	ConfirmConnection(m_world[96]->W(m_world[97]));
	ConfirmConnection(m_world[96]->E(m_world[94]));
	//A5
	ConfirmConnection(m_world[97]->N(m_world[98]));
	ConfirmConnection(m_world[97]->E(m_world[96]));
	//A6
	ConfirmConnection(m_world[98]->N(m_world[99]));
	ConfirmConnection(m_world[98]->S(m_world[97]));
	//A7
	ConfirmConnection(m_world[99]->N(m_world[100]));
	ConfirmConnection(m_world[99]->S(m_world[98]));
	//A8
	ConfirmConnection(m_world[100]->N(m_world[102]));
	ConfirmConnection(m_world[100]->W(m_world[101]));
	ConfirmConnection(m_world[100]->S(m_world[99]));
	//B2
	ConfirmConnection(m_world[101]->E(m_world[100]));
	//A9
	ConfirmConnection(m_world[102]->N(m_world[103]));
	ConfirmConnection(m_world[102]->S(m_world[100]));
	//A10
	ConfirmConnection(m_world[103]->E(m_world[104]));
	ConfirmConnection(m_world[103]->S(m_world[102]));
	//A11
	ConfirmConnection(m_world[104]->N(m_world[105]));
	ConfirmConnection(m_world[104]->W(m_world[103]));
	//A12
	ConfirmConnection(m_world[105]->N(m_world[106]));
	ConfirmConnection(m_world[105]->S(m_world[104]));
	//Map 9
	//A1
	ConfirmConnection(m_world[106]->N(m_world[107]));
	ConfirmConnection(m_world[106]->S(m_world[105]));
	//A2
	ConfirmConnection(m_world[107]->N(m_world[108]));
	ConfirmConnection(m_world[107]->S(m_world[106]));
	//A3
	ConfirmConnection(m_world[108]->N(m_world[109]));
	ConfirmConnection(m_world[108]->S(m_world[107]));
	//A4
	ConfirmConnection(m_world[109]->E(m_world[110]));
	ConfirmConnection(m_world[109]->S(m_world[108]));
	//A5
	ConfirmConnection(m_world[110]->E(m_world[111]));
	ConfirmConnection(m_world[110]->W(m_world[109]));
	//A6
	ConfirmConnection(m_world[111]->N(m_world[112]));
	ConfirmConnection(m_world[111]->W(m_world[110]));
	//A7
	ConfirmConnection(m_world[112]->W(m_world[113]));
	ConfirmConnection(m_world[112]->E(m_world[111]));
	//A8
	ConfirmConnection(m_world[113]->W(m_world[114]));
	ConfirmConnection(m_world[113]->E(m_world[112]));
	//A9
	ConfirmConnection(m_world[114]->W(m_world[115]));
	ConfirmConnection(m_world[114]->E(m_world[113]));
	//A10
	ConfirmConnection(m_world[115]->N(m_world[116]));
	ConfirmConnection(m_world[115]->E(m_world[114]));
	//A11
	ConfirmConnection(m_world[116]->N(m_world[117]));
	ConfirmConnection(m_world[116]->S(m_world[115]));
	//A12
	ConfirmConnection(m_world[117]->E(m_world[118]));
	ConfirmConnection(m_world[117]->S(m_world[116]));
	//A13
	ConfirmConnection(m_world[118]->E(m_world[119]));
	ConfirmConnection(m_world[118]->W(m_world[117]));
	//A14
	ConfirmConnection(m_world[119]->E(m_world[120]));
	ConfirmConnection(m_world[119]->W(m_world[118]));
	//A15
	ConfirmConnection(m_world[120]->N(m_world[121]));
	ConfirmConnection(m_world[120]->W(m_world[119]));
	//A16
	ConfirmConnection(m_world[121]->N(m_world[122]));
	ConfirmConnection(m_world[121]->S(m_world[120]));
	//Map 10
	//A1
	ConfirmConnection(m_world[122]->N(m_world[123]));
	ConfirmConnection(m_world[122]->S(m_world[121]));
	//A2
	ConfirmConnection(m_world[123]->N(m_world[124]));
	ConfirmConnection(m_world[123]->S(m_world[122]));
	//A3
	ConfirmConnection(m_world[124]->N(m_world[125]));
	ConfirmConnection(m_world[124]->S(m_world[123]));
	//A4
	ConfirmConnection(m_world[125]->N(m_world[126]));
	ConfirmConnection(m_world[125]->S(m_world[124]));
	//End
	ConfirmConnection(m_world[126]->S(m_world[125]));



	//ConfirmConnection(m_world[6]->S(m_world[5]));
	//ConfirmConnection(NS(m_world[1], m_world[0]));
	//ConfirmConnection(NS(m_world[0], m_world[1]));
	//ConfirmConnection(NS(m_world[1], m_world[2]));
	//ConfirmConnection(m_world[3]->N(m_world[2]));
}

World::~World()
{
	delete m_world;
}

int World::RoomCount()
{
	return m_roomCount;
}