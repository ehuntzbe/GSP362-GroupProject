#include "Items.h"

vector<Item> WorldItems::m_items (0);

void WorldItems::SpawnItems()
{
	int itemId = 0;
	Item WoodenSword;
	WoodenSword.SetStrBoost(1); //boost to strenth while worn
	WoodenSword.SetWearSlot(MAINHAND); //worn in the mainhand
	WoodenSword.SetName("woodsword"); //this is what the player types to get, wear, remove it
	WoodenSword.SetDesc("A wooden sword lies here, covered with splinters."); //this is what the player sees when the item is in the room
	WoodenSword.SetShort("a wooden sword"); //this is what the player sees when the item is worn or in their inventory
	WoodenSword.SetSaveLocation(IN_INVENTORY); //stored in the player's inventory
	WoodenSword.SetLocationId(0); //0, as in, this item is in the 1st slot of the inventory
	WoodenSword.SetItemId(itemId); //0, meaning you can access this item with m_items[0]
	m_items.push_back(WoodenSword);
	itemId++;
	PC->AddItem(WoodenSword); //test code

	Item LeatherCap;
	LeatherCap.SetAsBoost(2);
	LeatherCap.SetWearSlot(HEAD);
	LeatherCap.SetName("leathercap");
	LeatherCap.SetDesc("A leather cap is here, battered and faded.");
	LeatherCap.SetShort("a leather cap");
	LeatherCap.SetSaveLocation(IN_ROOM); //stored in a room
	LeatherCap.SetLocationId(1); //stored in room 1
	LeatherCap.SetItemId(itemId); //can be accessed with m_items[1]
	m_items.push_back(LeatherCap);
	itemId++;
}