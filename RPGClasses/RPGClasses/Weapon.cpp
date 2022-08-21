#include "Weapon.h"

int Weapon::m_numWeapons = 0;

Weapon::Weapon(std::string name)
{
	m_numWeapons++;
}

Weapon::~Weapon()
{

}

int Weapon::GetDamage()
{
	return m_minDamage + rand() % ((m_maxDamage - m_minDamage) + 1);
}