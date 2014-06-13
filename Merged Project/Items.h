#pragma once
#include "ItemStructure.h"
#include "Player.h"
#include "World.h"
#include <fstream>

struct WorldItems
{
	static vector<Item> m_items;
	static void SpawnItems();
	static void SaveItems();
	static void LoadItems();
	static void PlaceItems();
};