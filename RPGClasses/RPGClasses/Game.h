#pragma once
#include "Player.h"
#include "Enemy.h"

class Game
{
public:

	Game();
	~Game();

	void Run();

	enum Options
	{
		None = 0x0,
		Hardcore = 0x1,
		NoSound = 0x2,
		Debug = 0x4,
	};

private:

	void Round(int roundNumber);
	void Encounter();
	void PostEncounterOptions();

	void SetOptions(Options options);
	void SetOptions(bool hardCore, bool noSound, bool debug);

private:

	bool m_quit;
	Player* m_player;
	Enemy* m_enemy;

	Options m_options;

	bool m_hardcore;
	bool m_noSound;
	bool m_debug;
};