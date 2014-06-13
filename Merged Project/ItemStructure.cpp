#include "ItemStructure.h"
#include "Abilities.h"

Item::Item()
{
	m_itemName = "none";
	m_location = NOWHERE;
	m_roomId = -1;
	m_npcName = "none";
	m_hpBoost = 0;
	m_mpBoost = 0;
	m_strBoost = 0;
	m_agiBoost = 0;
	m_asBoost = 0;
	m_wearSlot = NONE;
	m_useItemAffect = HP;
	m_useItemAmount = 0;
	m_desc = "none";
	m_shortDesc = "none";
}