#include "NoWeapon.h"

NoWeapon::NoWeapon()
	: Weapon("NoWeapon")
{
	m_type = Weapon::None;
	m_minDamage = 1;
	m_maxDamage = 2;
}

NoWeapon::~NoWeapon()
{

}