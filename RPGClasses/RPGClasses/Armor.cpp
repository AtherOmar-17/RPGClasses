#include "Armor.h"

Armor::Armor()
{
	UpdateArmorStats(g_armorNone);
}

Armor::Armor(const int& armorType)
{
	UpdateArmorStats(armorType);
}

Armor::~Armor()
{

}

void Armor::UpdateArmorStats(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		m_bonusHealth = 0;
		m_dodgeRate = 0;
		break;

	case g_armorLight:
		m_bonusHealth = 10;
		m_dodgeRate = 20;
		break;

	case g_armorMedium:
		m_bonusHealth = 20;
		m_dodgeRate = 10;
		break;

	case g_armorHeavy:
		m_bonusHealth = 50;
		m_dodgeRate = 0;
		break;

	default:
		m_bonusHealth = 0;
		m_dodgeRate = 0;
	}
}