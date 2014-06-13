#pragma once
#include "ItemStructure.h"
#include "Player.h"
#include "World.h"

struct WorldItems
{
	static vector<Item> m_items;
	static void SpawnItems();
	static void LoadItems();
	static void PlaceItems();
};