#pragma once
#include "Weapon.h"

class NoWeapon : public Weapon
{
public:

	NoWeapon();
	~NoWeapon();

	std::string GetName() override { return "NoWeapon"; }
};