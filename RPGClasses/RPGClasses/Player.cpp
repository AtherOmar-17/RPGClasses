#include "Player.h"
#include <iostream>
#include <algorithm>

Player::Player()
	: m_maxHealth(100)
	, m_weapon(new Weapon())
	, m_armor(0)
{
	m_health = m_maxHealth;
}

Player::~Player()
{
	delete m_weapon;
	m_weapon = nullptr;
}

void Player::ChooseName()
{
	std::cout << "What is your name?" << std::endl;
	std::cin >> m_name;

	system("cls");
}

void Player::ChooseWeapon()
{
	system("cls");
	std::cout << "Choose your weapon" << std::endl;
	std::cout << 1 << ") Sword" << std::endl;
	std::cout << 2 << ") Axe" << std::endl;
	int weapon;
	std::cin >> weapon;
	m_weapon->UpdateWeaponStats(weapon);
}

void Player::ChooseArmor()
{
	system("cls");
	std::cout << "Choose your armor" << std::endl;
	std::cout << 1 << ") Light" << std::endl;
	std::cout << 2 << ") Medium" << std::endl;
	std::cout << 3 << ") Heavy" << std::endl;
	std::cin >> m_armor;
}

void Player::TakeDamage(int damage)
{
	m_health = std::clamp(m_health - damage, 0, m_health);
}

void Player::DisplayInfo()
{
	system("cls");
	std::cout << "Hello " << m_name << std::endl;
	std::cout << "Your Health is: " << m_health << std::endl;
	std::cout << "Your weapon of choice is: " << m_weapon->GetName() << std::endl;
	std::cout << "Your armor of choice is: " << m_armor << std::endl;
}