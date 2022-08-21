#pragma once
#include "Item.h"

class Weapon : public Item
{
public:

	enum WeaponType
	{
		None = 0,
		Sword,
		Axe,
		Max
	};

public:

	Weapon(std::string name);
	~Weapon();

	int GetDamage();

	WeaponType GetType() { return m_type; }

protected:

	static int m_numWeapons;

	WeaponType m_type;

	int m_minDamage;
	int m_maxDamage;
};