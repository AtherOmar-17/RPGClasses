#include "Player.h"
#include <algorithm>
#include "InputHelper.h"

#include "NoWeapon.h"
#include "Sword.h"
#include "Axe.h"

Player::Player()
	: m_maxHealth(100)
	, m_weapon(new NoWeapon())
	, m_armor(new Armor())
{
	m_health = m_maxHealth;
}

Player::~Player()
{
	delete m_weapon;
	m_weapon = nullptr;

	delete m_armor;
	m_armor = nullptr;
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

	delete m_weapon;
	m_weapon = nullptr;

	switch (weapon)
	{
	case Weapon::WeaponType::Sword:
		m_weapon = new Sword();
		break;

	case Weapon::WeaponType::Axe:
		m_weapon = new Axe();
		break;

	default:
		m_weapon = new NoWeapon();
		break;
	}
}

void Player::ChooseArmor()
{
	system("cls");
	std::cout << "Choose your armor" << std::endl;
	std::cout << 1 << ") Light" << std::endl;
	std::cout << 2 << ") Medium" << std::endl;
	std::cout << 3 << ") Heavy" << std::endl;
	int armor;
	std::cin >> armor;
	m_armor->UpdateArmorStats(armor);
}

void Player::TakeDamage(int damage)
{
	m_health = std::clamp(m_health - damage, 0, m_health);
}

void Player::Rest()
{
	constexpr int restHealing = 20;

	m_health = std::clamp(m_health + restHealing, 0, m_maxHealth);
	std::cout << "You healed " << restHealing << "!" << std::endl;
	std::cout << "You now have " << m_health << " Health" << std::endl;

	InputHelper::PressAnyKeyToContinue();
}

void Player::DisplayInfo()
{
	system("cls");
	std::cout << "Hello " << m_name << std::endl;
	std::cout << "Your Health is: " << m_health << std::endl;
	std::cout << "Your weapon of choice is: " << m_weapon->GetName() << std::endl;
	std::cout << "Your armor of choice is: " << m_armor->GetName() << std::endl;

	InputHelper::PressAnyKeyToContinue();
}