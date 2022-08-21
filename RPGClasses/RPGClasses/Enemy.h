#pragma once
#include <string>
#include "Weapon.h"
#include "Armor.h"

class Enemy
{
public:

	Enemy();
	~Enemy();

	Weapon* GetWeapon() { return m_weapon; }
	Armor* GetArmor() { return m_armor; }

	int GetHealth() { return m_health; }

	void DisplayInfo();

	void TakeDamage(int damage);

private:

	int m_health;
	Weapon* m_weapon;
	Armor* m_armor;
};