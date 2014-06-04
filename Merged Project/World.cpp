#include "World.h"

World::World()
{
	m_world = NULL;
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

void World::LoadNpcsFromFile(string npc_fileName, Room* test)
{
	//test->NpcResize(test->GetNumNpc());
	ifstream myfile (npc_fileName);
	string m_line;
	int tempcount = 0;

	if (myfile.is_open())
	{
		//getline (myfile,m_line);
		while ( getline (myfile,m_line) )
		{
			if(m_line == test->GetName())
			{
				for(int a = 0; a < test->GetNumNpc(); a++)
				{
				Character m_npc;
				Combatant temp;

				getline (myfile,m_line);
				m_npc.SetName(m_line);
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

				m_npc.SetStats(temp);

				test->NpcAdd(m_npc);

				tempcount++;
				}
			}

			/*else
			{
				cout << "Unable to Load file";
			}*/
			if(tempcount == test->GetNumNpc())
			{
				myfile.close();
			}
		}
	}
	else cout << "Unable to open file Load failed"; 
}

void World::LoadRoomsFromFile(string p_fileName, string npc_fileName)
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
					LoadNpcsFromFile(npc_fileName, m_world[counter]);
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