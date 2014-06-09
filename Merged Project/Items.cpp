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

	//armor - basic cotton stuff
	//HEAD, SHOULDERS, ARMS, HANDS, BODY, LEGS, FEET

	Item CottonCap;
	CottonCap.SetAsBoost(2);
	CottonCap.SetWearSlot(HEAD);
	CottonCap.SetName("CottonCap");
	CottonCap.SetDesc("A cotton cap is here, battered and faded.");
	CottonCap.SetShort("a cotton cap");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[1]
	m_items.push_back(CottonCap);
	itemId++;

	Item CottonShoulder;
	CottonCap.SetAsBoost(1);
	CottonCap.SetWearSlot(SHOULDERS);
	CottonCap.SetName("CottonSpaulders");
	CottonCap.SetDesc("A set of cotton spaulders is here, battered and faded.");
	CottonCap.SetShort("cotton spaulders");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[2]
	m_items.push_back(CottonShoulder);
	itemId++;

	Item CottonArms;
	CottonCap.SetAsBoost(2);
	CottonCap.SetWearSlot(ARMS);
	CottonCap.SetName("CottonElbowPads");
	CottonCap.SetDesc("A set of cotton elbow pads is here, battered and faded.");
	CottonCap.SetShort("cotton elbow pads");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[3]
	m_items.push_back(CottonArms);
	itemId++;

	Item CottonHands; 
	CottonCap.SetAsBoost(1);
	CottonCap.SetWearSlot(HANDS);
	CottonCap.SetName("CottonGloves");
	CottonCap.SetDesc("A set of cotton gloves is here, battered and faded.");
	CottonCap.SetShort("cotton gloves");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[4]
	m_items.push_back(CottonHands);
	itemId++;

	Item CottonBody; 
	CottonCap.SetAsBoost(3);
	CottonCap.SetWearSlot(BODY);
	CottonCap.SetName("CottonShirt");
	CottonCap.SetDesc("A cotton shirt is here, battered and faded.");
	CottonCap.SetShort("a cotton shirt");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[5]
	m_items.push_back(CottonBody);
	itemId++;

	Item CottonLegs; 
	CottonCap.SetAsBoost(2);
	CottonCap.SetWearSlot(LEGS);
	CottonCap.SetName("CottonPants");
	CottonCap.SetDesc("A pair of cotton pants is here, battered and faded.");
	CottonCap.SetShort("cotton pants");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[6]
	m_items.push_back(CottonLegs);
	itemId++;

	Item CottonFeet;
	CottonCap.SetAsBoost(3);
	CottonCap.SetWearSlot(FEET);
	CottonCap.SetName("CottonShoes");
	CottonCap.SetDesc("A pair of cotton shoes is here, battered and faded.");
	CottonCap.SetShort("cotton shoes");
	CottonCap.SetSaveLocation(IN_ROOM); //stored in a room
	CottonCap.SetLocationId(1); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[7]
	m_items.push_back(CottonFeet);
	itemId++;		
}