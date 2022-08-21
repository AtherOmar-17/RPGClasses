#pragma once
#include <iostream>

namespace InputHelper
{
	inline void PressAnyKeyToContinue()
	{
		std::cout << "Press any key to continue" << std::endl;
		std::cin.ignore();
		std::cin.get();
	}
}