#pragma once
#include <string>
#include "Weapon.h"

class Player
{
public:

	Player();
	~Player();

	void ChooseName();
	void ChooseWeapon();
	void ChooseArmor();

	Weapon* GetWeapon() { return m_weapon; }
	int GetArmor() { return m_armor; }

	int GetHealth() const { return m_health; }

	void DisplayInfo();

	void TakeDamage(int damage);

private:

	std::string m_name;
	int m_health;
	int m_maxHealth;
	Weapon* m_weapon;
	int m_armor;
};