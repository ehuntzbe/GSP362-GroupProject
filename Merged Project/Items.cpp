#include "Items.h"

void LoadItems()
{
	Item WoodenSword;
	WoodenSword.SetStrBoost(1); //boost to strenth while worn
	WoodenSword.SetWearSlot(MAINHAND); //worn in the mainhand
	WoodenSword.SetName("woodsword"); //this is what the player types to get, wear, remove it
	WoodenSword.SetDesc("A wooden sword lies here, covered with splinters."); //this is what the player sees when the item is in the room
	WoodenSword.SetShort("a wooden sword"); //this is what the player sees when the item is worn or in their inventory

	Item LeatherCap;
	LeatherCap.SetAsBoost(2);
	LeatherCap.SetWearSlot(HEAD);
	LeatherCap.SetName("leathercap");
	LeatherCap.SetDesc("A leather cap is here, battered and faded.");
	LeatherCap.SetShort("a leather cap");
}