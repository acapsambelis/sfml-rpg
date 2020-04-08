#pragma once
#include "Logic\Game.h"
#include "Graphics\Display.h"
#include "SaveMachine.h"
#include "..\Character\Player.h"
#include "..\WorldItems\World.h"
#include "..\WorldItems\WorldObject.h"
#include "..\WorldItems\ObjectDisperse.h"

class Control
{
public:
	Control();
	~Control();

	void InitializePlayer();
	void InitializeWorld();

	void Loop();

	void Reload();

	void Save();

	void Play();

private:
	bool playing;

	Player player;
	World world;

	SaveMachine saveMachine;

	Game game;
	Display display;
};
