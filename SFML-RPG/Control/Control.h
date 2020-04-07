#pragma once
#include <SFML\Graphics.hpp>
#include "Logic\Game.h"
#include "Graphics\Display.h"
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

	void Play();

private:
	bool playing;

	Player player;
	World world;

	Game game;
	Display display;
};

