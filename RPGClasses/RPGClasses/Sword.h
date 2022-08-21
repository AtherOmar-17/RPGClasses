#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:

	Sword();
	~Sword();

	std::string GetName() override { return "Sword"; }
};