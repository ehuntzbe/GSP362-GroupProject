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
	cout << "EXITS:"; m_world[p_roomID]->DisplayExits(); cout << endl;
}

void World::LoadRoomsFromFile(string p_fileName)
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