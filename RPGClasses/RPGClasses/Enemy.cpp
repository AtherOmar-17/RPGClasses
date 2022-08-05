#include "Enemy.h"
#include <iostream>
#include <algorithm>
Enemy::Enemy()
	: m_health(100)
	, m_weapon(new Weapon(rand() % Weapon::g_weaponMax))
	, m_armor(0)
{

}

Enemy::~Enemy()
{
	delete m_weapon;
	m_weapon = nullptr;
}

void Enemy::TakeDamage(int damage)
{
	m_health = std::clamp(m_health - damage, 0, m_health);
}

void Enemy::DisplayInfo()
{
	system("cls");
	std::cout << "You Encountered an Enemy" << std::endl;
	std::cout << "Their Health is: " << m_health << std::endl;
	std::cout << "Their weapon is: " << m_weapon->GetName() << std::endl;
	std::cout << "Their armor is: " << m_armor << std::endl;
}