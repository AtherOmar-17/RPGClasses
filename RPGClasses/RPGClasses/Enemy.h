#pragma once
#include <string>
#include "Weapon.h"

class Enemy
{
public:

	Enemy();
	~Enemy();

	Weapon* GetWeapon() { return m_weapon; }
	int GetArmor() { return m_armor; }

	int GetHealth() { return m_health; }

	void DisplayInfo();

	void TakeDamage(int damage);

private:

	int m_health;
	Weapon* m_weapon;
	int m_armor;
};