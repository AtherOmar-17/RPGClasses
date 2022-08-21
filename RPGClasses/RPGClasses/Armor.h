#pragma once
#include "Item.h"

class Armor : public Item
{
public:

	static const int g_armorNone = 0;
	static const int g_armorLight = 1;
	static const int g_armorMedium = 2;
	static const int g_armorHeavy = 3;
	static const int g_armorMax = 4;

public:

	Armor();
	Armor(const int& armorType);
	~Armor();

	int GetBonusHealth() { return m_bonusHealth; }

	int GetDodgeRate() { return m_dodgeRate; }

	void UpdateArmorStats(int armor);

private:

	int m_bonusHealth;
	int m_dodgeRate;
};