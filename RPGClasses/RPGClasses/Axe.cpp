#include "Axe.h"

Axe::Axe()
	: Weapon("Axe")
{
	m_type = Weapon::Axe;
	m_minDamage = 2;
	m_maxDamage = 8;
}

Axe::~Axe()
{

}