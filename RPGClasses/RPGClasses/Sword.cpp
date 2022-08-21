#include "Sword.h"

Sword::Sword()
	: Weapon("Sword")
{
	m_minDamage = 4;
	m_maxDamage = 6;

	m_type = Weapon::Sword;
}

Sword::~Sword()
{

}