#include "Enemy.h"
#include <iostream>
#include <algorithm>
#include "NoWeapon.h"
Enemy::Enemy()
	: m_health(100)
	, m_weapon(new NoWeapon())
	, m_armor(new Armor(rand() % Armor::g_armorMax))
{

}

Enemy::~Enemy()
{
	delete m_weapon;
	m_weapon = nullptr;

	delete m_armor;
	m_armor = nullptr;
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
	std::cout << "Their armor is: " << m_armor->GetName() << std::endl;
}