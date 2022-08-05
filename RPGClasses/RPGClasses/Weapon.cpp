#include "Weapon.h"

Weapon::Weapon()
	: m_name("No Weapon")
	, m_minDamage(1)
	, m_maxDamage(2)
{

}

Weapon::Weapon(int weaponType)
{
	UpdateWeaponStats(weaponType);
}

Weapon::~Weapon()
{

}

void Weapon::UpdateWeaponStats(int weapon)
{
	switch (weapon)
	{
	case g_weaponNone:
		m_minDamage = 1;
		m_maxDamage = 2;
		m_name = "None";
		break;

	case g_weaponSword:
		m_minDamage = 4;
		m_maxDamage = 6;
		m_name = "Sword";
		break;

	case g_weaponAxe:
		m_minDamage = 2;
		m_maxDamage = 9;
		m_name = "Axe";
		break;

	default:
		m_name = "Unknown";
	}
}

int Weapon::GetDamage()
{
	return m_minDamage + rand() % ((m_maxDamage - m_minDamage) + 1);
}