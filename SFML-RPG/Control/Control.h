#pragma once
#include <SFML\Graphics.hpp>
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


	void GenerateWorld();


	void Loop();

	void Play();

private:
	bool playing;

	Player player;
	World world;

	SaveMachine saveMachine;

	Game game;
	Display display;
};

