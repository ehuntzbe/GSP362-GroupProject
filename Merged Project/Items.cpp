#include "Items.h"

vector<Item> WorldItems::m_items (0);

void WorldItems::SpawnItems()
{
	int itemId = 0;
	Item WoodenSword;
	WoodenSword.SetStrBoost(1); //boost to strenth while worn
	WoodenSword.SetWearSlot(OFFHAND); //worn in the mainhand
	WoodenSword.SetName("woodsword"); //this is what the player types to get, wear, remove it
	WoodenSword.SetDesc("A wooden sword lies here, covered with splinters."); //this is what the player sees when the item is in the room
	WoodenSword.SetShort("a wooden sword"); //this is what the player sees when the item is worn or in their inventory
	WoodenSword.SetSaveLocation(IN_INVENTORY); //stored in the player's inventory
	WoodenSword.SetLocationId(0); //0, as in, this item is in the 1st slot of the inventory
	WoodenSword.SetItemId(itemId); //0, meaning you can access this item with m_items[0]
	m_items.push_back(WoodenSword);
	itemId++;
	PC->AddItem(WoodenSword); //test code


	Item WeakHerb;
	WeakHerb.SetWearSlot(NONE);
	WeakHerb.SetName("weakherb");
	WeakHerb.SetDesc("An herb is growing here. It may have medicinal uses.");
	WeakHerb.SetShort("a weak herb");
	WeakHerb.SetSaveLocation(IN_ROOM);
	WeakHerb.SetLocationId(1);
	WeakHerb.SetItemId(itemId);
	WeakHerb.SetUseAffect(HP);
	WeakHerb.SetUseAffectAmount(5);
	m_items.push_back(WeakHerb);
	itemId++;
	PC->AddItem(WeakHerb); //test code

	//armor - basic cotton stuff
	//HEAD, SHOULDERS, ARMS, HANDS, BODY, LEGS, FEET

	Item CottonCap;
	CottonCap.SetAsBoost(2);
	CottonCap.SetWearSlot(HEAD);
	CottonCap.SetName("cottoncap");
	CottonCap.SetDesc("A cotton cap is here, battered and faded.");
	CottonCap.SetShort("a cotton cap");
	CottonCap.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonCap.SetLocationId(2); //stored in room 1
	CottonCap.SetItemId(itemId); //can be accessed with m_items[1]
	m_items.push_back(CottonCap);
	itemId++;
	PC->AddItem(CottonCap);

	Item CottonShoulder;
	CottonShoulder.SetAsBoost(1);
	CottonShoulder.SetWearSlot(SHOULDERS);
	CottonShoulder.SetName("cottonspaulders");
	CottonShoulder.SetDesc("A set of cotton spaulders is here, battered and faded.");
	CottonShoulder.SetShort("cotton spaulders");
	CottonShoulder.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonShoulder.SetLocationId(0); //stored in room 1
	CottonShoulder.SetItemId(itemId); //can be accessed with m_items[2]
	m_items.push_back(CottonShoulder);
	itemId++;
	PC->AddItem(CottonShoulder);

	Item CottonArms;
	CottonArms.SetAsBoost(2);
	CottonArms.SetWearSlot(ARMS);
	CottonArms.SetName("cottonelbowpads");
	CottonArms.SetDesc("A set of cotton elbow pads is here, battered and faded.");
	CottonArms.SetShort("cotton elbow pads");
	CottonArms.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonArms.SetLocationId(4); //stored in room 1
	CottonArms.SetItemId(itemId); //can be accessed with m_items[3]
	m_items.push_back(CottonArms);
	itemId++;
	PC->AddItem(CottonArms);

	Item CottonHands; 
	CottonHands.SetAsBoost(1);
	CottonHands.SetWearSlot(HANDS);
	CottonHands.SetName("cottongloves");
	CottonHands.SetDesc("A set of cotton gloves is here, battered and faded.");
	CottonHands.SetShort("cotton gloves");
	CottonHands.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonHands.SetLocationId(5); //stored in room 1
	CottonHands.SetItemId(itemId); //can be accessed with m_items[4]
	m_items.push_back(CottonHands);
	itemId++;
	PC->AddItem(CottonHands);

	Item CottonBody; 
	CottonBody.SetAsBoost(3);
	CottonBody.SetWearSlot(BODY);
	CottonBody.SetName("cottonshirt");
	CottonBody.SetDesc("A cotton shirt is here, battered and faded.");
	CottonBody.SetShort("a cotton shirt");
	CottonBody.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonBody.SetLocationId(6); //stored in room 1
	CottonBody.SetItemId(itemId); //can be accessed with m_items[5]
	m_items.push_back(CottonBody);
	itemId++;
	PC->AddItem(CottonBody);

	Item CottonLegs; 
	CottonLegs.SetAsBoost(2);
	CottonLegs.SetWearSlot(LEGS);
	CottonLegs.SetName("cottonpants");
	CottonLegs.SetDesc("A pair of cotton pants is here, battered and faded.");
	CottonLegs.SetShort("cotton pants");
	CottonLegs.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonLegs.SetLocationId(7); //stored in room 1
	CottonLegs.SetItemId(itemId); //can be accessed with m_items[6]
	m_items.push_back(CottonLegs);
	itemId++;
	PC->AddItem(CottonLegs);

	Item CottonFeet;
	CottonFeet.SetAsBoost(3);
	CottonFeet.SetWearSlot(FEET);
	CottonFeet.SetName("cottonshoes");
	CottonFeet.SetDesc("A pair of cotton shoes is here, battered and faded.");
	CottonFeet.SetShort("cotton shoes");
	CottonFeet.SetSaveLocation(IN_INVENTORY); //stored in inventory
	CottonFeet.SetLocationId(8); //stored in room 1
	CottonFeet.SetItemId(itemId); //can be accessed with m_items[7]
	m_items.push_back(CottonFeet);
	itemId++;	
	PC->AddItem(CottonFeet);
}