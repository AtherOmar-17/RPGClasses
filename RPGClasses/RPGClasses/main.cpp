#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <locale>

#include "Player.h"
#include "Enemy.h"
#include "Game.h"

constexpr int g_armorNone = 0;
constexpr int g_armorLight = 1;
constexpr int g_armorMedium = 2;
constexpr int g_armorHeavy = 3;
constexpr int g_armorMax = 4;

//Helper functions

std::string GetArmorName(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		return "None";
		break;

	case g_armorLight:
		return "Light Armor";
		break;

	case g_armorMedium:
		return "Medium Armor";
		break;

	case g_armorHeavy:
		return "Heavy Armor";
		break;

	default:
		return "Unknown";
	}
}

int GetArmorBonusHealth(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		return 0;
		break;

	case g_armorLight:
		return 10;
		break;

	case g_armorMedium:
		return 20;
		break;

	case g_armorHeavy:
		return 50;
		break;

	default:
		return 0;
	}
}

int GetArmorDodgeRate(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		return 0;
		break;

	case g_armorLight:
		return 20;
		break;

	case g_armorMedium:
		return 10;
		break;

	case g_armorHeavy:
		return 0;
		break;

	default:
		return 0;
	}
}

void PressAnyKeyToContinue()
{
	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();
}

//Game logic

void Rest(int& playerHealth, int playerMaxHealth)
{
	constexpr int restHealing = 20;

	playerHealth = std::clamp(playerHealth + restHealing, 0, playerMaxHealth);
	std::cout << "You healed " << restHealing << "!" << std::endl;
	std::cout << "You now have " << playerHealth << " Health" << std::endl;

	PressAnyKeyToContinue();
}

void Round(int roundNumber, Player& player, Enemy& enemy)
{
	system("cls");

	std::cout << "Round " << roundNumber << std::endl;

	int playerDodge = GetArmorDodgeRate(player.GetArmor());
	int enemyDodge = GetArmorDodgeRate(enemy.GetArmor());

	int playerAttack = player.GetWeapon()->GetDamage();
	int enemyAttack = enemy.GetWeapon()->GetDamage();

	if (playerDodge > rand() % 101)
	{
		std::cout << "You dodged the enemy's attack!" << std::endl;
		enemyAttack = 0;
	}

	if (enemyDodge > rand() % 101)
	{
		std::cout << "The enemy dodged your attack!" << std::endl;
		playerAttack = 0;
	}

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;

	enemy.TakeDamage(playerAttack);
	player.TakeDamage(enemyAttack);

	std::cout << "Your Health is: " << player.GetHealth() << std::endl;
	std::cout << "The Enemy Health is: " << enemy.GetHealth() << std::endl;

	PressAnyKeyToContinue();
}

void Encounter(Player& player)
{
	system("cls");

	Enemy enemy;

	enemy.DisplayInfo();

	PressAnyKeyToContinue();

	for (int i = 1; player.GetHealth() > 0 && enemy.GetHealth() > 0; i++)
	{
		Round(i, player, enemy);
	}

	system("cls");

	std::cout << "You have " << player.GetHealth() << " Health Left" << std::endl;
	std::cout << "The Enemy has " << enemy.GetHealth() << " Health Left" << std::endl;

	if (player.GetHealth() > enemy.GetHealth())
	{
		std::cout << "You Win!" << std::endl;
	}
	else if (player.GetHealth() < enemy.GetHealth())
	{
		std::cout << "You Lose..." << std::endl;
	}
	else
	{
		std::cout << "It's a tie?" << std::endl;
	}

	PressAnyKeyToContinue();
}

void PostEncounterOptions(bool& quit, int& playerHealth, int playerMaxHealth)
{
	std::cout << "What would you like to do now?" << std::endl;
	std::cout << "- Rest" << std::endl;
	std::cout << "- Quit" << std::endl;
	std::string choice;
	std::cin >> choice;

	if (choice == "Rest" || choice == "rest")
	{
		Rest(playerHealth, playerMaxHealth);
	}
	else if (choice == "Quit" || choice == "quit")
	{
		quit = true;
	}
}

void PlayGame()
{
	srand(time(NULL));

	std::cout << "Welcome to my RPG Game!" << std::endl;

	Player player;

	player.ChooseName();
	player.ChooseWeapon();
	player.ChooseArmor();

	std::string armorName = GetArmorName(player.GetArmor());

	PressAnyKeyToContinue();

	bool quit = false;

	do
	{
		Encounter(player);

		if (player.GetHealth() > 0)
		{
			//PostEncounterOptions(quit, playerHealth, playerMaxHealth);
		}
		else
		{
			quit = true;
		}

	} while (player.GetHealth() > 0 && !quit);
}

int main()
{
	PlayGame();
}