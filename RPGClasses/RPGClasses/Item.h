#pragma once
#include <string>

class Item
{
public:

	Item();

	virtual std::string GetName() { return "UnKnown"; }
};