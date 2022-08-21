#pragma once
#include "Weapon.h"

class Axe : public Weapon
{
public:

	Axe();
	~Axe();

	std::string GetName() override { return "Axe"; }
};