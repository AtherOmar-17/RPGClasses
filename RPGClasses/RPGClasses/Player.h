#pragma once
#include <string>
#include "Weapon.h"
#include "Armor.h"

class Player
{
public:

	Player();
	~Player();

	void ChooseName();
	void ChooseWeapon();
	void ChooseArmor();

	Weapon* GetWeapon() { return m_weapon; }
	Armor* GetArmor() { return m_armor; }

	int GetHealth() const { return m_health; }

	void DisplayInfo();

	void TakeDamage(int damage);

	void Rest();

private:

	std::string m_name;
	int m_health;
	int m_maxHealth;
	Weapon* m_weapon;
	Armor* m_armor;
};