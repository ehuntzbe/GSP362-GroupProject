#include "Items.h"

vector<Item> WorldItems::m_items (0);

void WorldItems::SpawnItems()
{
	Item WoodenSword;
	WoodenSword.SetStrBoost(1); //boost to strenth while worn
	WoodenSword.SetWearSlot(OFFHAND); //worn in the mainhand
	WoodenSword.SetName("woodsword"); //this is what the player types to get, wear, remove it
	WoodenSword.SetDesc("A wooden sword lies here, covered with splinters."); //this is what the player sees when the item is in the room
	WoodenSword.SetShort("a wooden sword"); //this is what the player sees when the item is worn or in their inventory
	WoodenSword.SetSaveLocation(IN_INVENTORY); //stored in the player's inventory
	m_items.push_back(WoodenSword);

	Item WeakHerb;
	WeakHerb.SetWearSlot(NONE);
	WeakHerb.SetName("weakherb");
	WeakHerb.SetDesc("An herb is growing here. It may have medicinal uses.");
	WeakHerb.SetShort("a weak herb");
	WeakHerb.SetSaveLocation(IN_ROOM);
	WeakHerb.SetRoomId(1);
	WeakHerb.SetUseAffect(HP);
	WeakHerb.SetUseAffectAmount(5);
	m_items.push_back(WeakHerb);

	//armor - basic cotton stuff
	//HEAD, SHOULDERS, ARMS, HANDS, BODY, LEGS, FEET

	Item CottonCap;
	CottonCap.SetAsBoost(2);
	CottonCap.SetWearSlot(HEAD);
	CottonCap.SetName("cottoncap");
	CottonCap.SetDesc("A cotton cap is here, battered and faded.");
	CottonCap.SetShort("a cotton cap");
	CottonCap.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonCap);

	Item CottonShoulder;
	CottonShoulder.SetAsBoost(1);
	CottonShoulder.SetWearSlot(SHOULDERS);
	CottonShoulder.SetName("cottonspaulders");
	CottonShoulder.SetDesc("A set of cotton spaulders is here, battered and faded.");
	CottonShoulder.SetShort("cotton spaulders");
	CottonShoulder.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonShoulder);

	Item CottonArms;
	CottonArms.SetAsBoost(2);
	CottonArms.SetWearSlot(ARMS);
	CottonArms.SetName("cottonelbowpads");
	CottonArms.SetDesc("A set of cotton elbow pads is here, battered and faded.");
	CottonArms.SetShort("cotton elbow pads");
	CottonArms.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonArms);

	Item CottonHands; 
	CottonHands.SetAsBoost(1);
	CottonHands.SetWearSlot(HANDS);
	CottonHands.SetName("cottongloves");
	CottonHands.SetDesc("A set of cotton gloves is here, battered and faded.");
	CottonHands.SetShort("cotton gloves");
	CottonHands.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonHands);

	Item CottonBody; 
	CottonBody.SetAsBoost(3);
	CottonBody.SetWearSlot(BODY);
	CottonBody.SetName("cottonshirt");
	CottonBody.SetDesc("A cotton shirt is here, battered and faded.");
	CottonBody.SetShort("a cotton shirt");
	CottonBody.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonBody);

	Item CottonLegs; 
	CottonLegs.SetAsBoost(2);
	CottonLegs.SetWearSlot(LEGS);
	CottonLegs.SetName("cottonpants");
	CottonLegs.SetDesc("A pair of cotton pants is here, battered and faded.");
	CottonLegs.SetShort("cotton pants");
	CottonLegs.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonLegs);

	Item CottonFeet;
	CottonFeet.SetAsBoost(3);
	CottonFeet.SetWearSlot(FEET);
	CottonFeet.SetName("cottonshoes");
	CottonFeet.SetDesc("A pair of cotton shoes is here, battered and faded.");
	CottonFeet.SetShort("cotton shoes");
	CottonFeet.SetSaveLocation(IN_INVENTORY); //stored in inventory
	m_items.push_back(CottonFeet);

	PlaceItems();
}

void WorldItems::LoadItems()
{

}

void WorldItems::PlaceItems()
{
	Room* *worldCopy = World::GetInstance()->GetRooms();
	for (vector<Item>::iterator it = m_items.begin(); it != m_items.end(); ++it)
	{
		switch(it->GetSaveLocation())
		{
		case NOWHERE:

			break;
		case IN_INVENTORY:
			PC->AddItem(*it);
			break;
		case IN_EQUIPMENT:
			PC->EquipItem(*it);
			break;
		case IN_ROOM:
			World::GetInstance()->GetRooms()[it->GetRoomId()]->AddItem(*it);
			break;
		case IN_NPC:
			worldCopy[it->GetRoomId()]->GetNPC(it->GetNpcName()).AddItem(*it);
			break;
		}
	}
}