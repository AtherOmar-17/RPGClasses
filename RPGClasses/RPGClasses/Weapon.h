#pragma once
#include <string>

class Weapon
{
public:

	static const int g_weaponNone = 0;
	static const int g_weaponSword = 1;
	static const int g_weaponAxe = 2;
	static const int g_weaponMax = 3;

public:

	Weapon();
	Weapon(int weaponType);
	~Weapon();

	int GetDamage();
	void UpdateWeaponStats(int weapon);

	std::string GetName() { return m_name; }

private:

	std::string m_name;
	int m_minDamage;
	int m_maxDamage;
};