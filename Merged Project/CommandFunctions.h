//Cory J. 6/5
#include "Room.h"
#include "Player.h"
#include "Combat.h"
#include "Abilities.h"
#include "Interface.h"
#include "Items.h"
#include <sstream>

void Look();
void Kill(string p_target);
void North();
void South();
void East();
void West();
void Up();
void Down();
void Score();
void Inventory();
void Abilities();
void Help();
void Growth();
bool Quit();
void Equipment();
void Wear(string p_target);
void Remove(string p_target);
void ExaInv();
void ExaEquip();
void ExaLook();
void Get(string p_target);
void Drop(string p_target);
void Use(string p_target);