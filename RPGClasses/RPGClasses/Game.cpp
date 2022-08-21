#include "Game.h"
#include <time.h>
#include "InputHelper.h"
#include "Sword.h"
#include "Axe.h"

Game::Game()
	: m_quit(false)
	, m_player(new Player())
	, m_enemy(nullptr)
{
	SetOptions((Options)(Hardcore | NoSound));

	SetOptions(true, true, false);

	if (m_hardcore)
	{
		std::cout << "Round "<< std::endl;
	}
	 
	if (m_options & Hardcore)
	{
		std::cout << "Round "<< std::endl;
	}
}

Game::~Game()
{
	delete m_player;
	m_player = nullptr;

	if (m_enemy != nullptr)
	{
		delete m_enemy;
		m_enemy = nullptr;
	}
}

void Game::SetOptions(Options options)
{
	m_options = options;
}

void Game::SetOptions(bool hardCore, bool noSound, bool debug)
{
	m_hardcore = hardCore;
	m_noSound = noSound;
	m_debug = debug;
}

void Game::Round(int roundNumber)
{
	system("cls");

	std::cout << "Round " << roundNumber << std::endl;

	int playerDodge = m_player->GetArmor()->GetDodgeRate();
	int enemyDodge = m_enemy->GetArmor()->GetDodgeRate();

	int playerAttack = m_player->GetWeapon()->GetDamage();
	int enemyAttack = m_enemy->GetWeapon()->GetDamage();

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

	m_enemy->TakeDamage(playerAttack);
	m_player->TakeDamage(enemyAttack);

	std::cout << "Your Health is: " << m_player->GetHealth() << std::endl;
	std::cout << "The Enemy Health is: " << m_enemy->GetHealth() << std::endl;

	InputHelper::PressAnyKeyToContinue();
}

void Game::Encounter()
{
	system("cls");

	if (m_enemy != nullptr)
	{
		delete m_enemy;
		m_enemy = nullptr;
	}

	m_enemy = new Enemy();

	m_enemy->DisplayInfo();

	InputHelper::PressAnyKeyToContinue();

	for (int i = 1; m_player->GetHealth() > 0 && m_enemy->GetHealth() > 0; i++)
	{
		Round(i);
	}

	system("cls");

	std::cout << "You have " << m_player->GetHealth() << " Health Left" << std::endl;
	std::cout << "The Enemy has " << m_enemy->GetHealth() << " Health Left" << std::endl;

	if (m_player->GetHealth() > m_enemy->GetHealth())
	{
		std::cout << "You Win!" << std::endl;
		return;
	}
	else if (m_player->GetHealth() < m_enemy->GetHealth())
	{
		std::cout << "You Lose..." << std::endl;
	}
	else
	{
		std::cout << "It's a tie?" << std::endl;
	}

	InputHelper::PressAnyKeyToContinue();
}

void Game::PostEncounterOptions()
{
	std::cout << "What would you like to do now?" << std::endl;
	std::cout << "- Rest" << std::endl;
	std::cout << "- Quit" << std::endl;
	std::string choice;
	std::cin >> choice;

	if (choice == "Rest" || choice == "rest")
	{
		m_player->Rest();
	}
	else if (choice == "Quit" || choice == "quit")
	{
		m_quit = true;
	}
}

void Game::Run()
{
	srand(time(NULL));

	std::cout << "Welcome to my RPG Game!" << std::endl;
	
	m_player->ChooseName();
	m_player->ChooseWeapon();
	m_player->ChooseArmor();
	
	m_player->DisplayInfo();
	
	InputHelper::PressAnyKeyToContinue();
	
	do
	{
		Encounter();
	
		if (m_player->GetHealth() > 0)
		{
			PostEncounterOptions();
		}
		else
		{
			m_quit = true;
		}
	
	} while (m_player->GetHealth() > 0 && !m_quit);
}