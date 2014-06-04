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
			Combatant tempStats;
						
			temp = m_world[p_roomID]->NpcList();
			tempStats = temp[a].GetStats();

			cout << "Name: "<< temp[a].GetName() <<endl;				
			cout << "Max HP: "<< tempStats.GetMaxHp() <<endl;		
			cout << "Max MP: "<< tempStats.GetMaxMp() <<endl;		
			cout << "Max Str: "<< tempStats.GetMaxStr() <<endl;		
			cout << "Max Agi: "<< tempStats.GetMaxAgi() <<endl;		
			cout << "Max As: "<< tempStats.GetMaxAs() <<endl;		
			cout << "HP: "<< tempStats.GetHp() <<endl;			
			cout << "MP: "<< tempStats.GetMp() <<endl;			
			cout << "Str: "<< tempStats.GetStr() <<endl;			
			cout << "Agi: "<< tempStats.GetAgi() <<endl;			
			cout << "As: "<< tempStats.GetAs() <<endl;
			cout << "Exp: "<< tempStats.GetExp() <<endl <<endl;
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
				m_npc.SetName(line);
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

				m_npc.SetStats(temp);

				p_room->NpcAdd(m_npc);

				tempcount++;
				}
			}

			/*else
			{
				cout << "Unable to Load file";
			}*/
			if(tempcount == p_room->GetNumNpc())
			{
				myfile.close();
			}
		}
	}
	else cout << "Unable to open file Load failed"; 
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
				m_world[counter]->SetDesc(line);
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
	PC->SetCurrentRoom(m_world[0]);
	ConfirmConnection(NS(m_world[1], m_world[0]));
	ConfirmConnection(NS(m_world[0], m_world[1]));
	ConfirmConnection(m_world[3]->N(m_world[2]));
}

World::~World()
{
	delete m_world;
}

int World::RoomCount()
{
	return m_roomCount;
}