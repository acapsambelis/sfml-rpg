#include "Control.h"

Control::Control()
{
	playing = true;
}

Control::~Control()
{
}

void Control::InitializePlayer()
{
	this->player = saveMachine.loadPlayer("Saves/Test.txt");
	display.InitializePlayer(player);
}

void Control::InitializeWorld()
{
	this->world = saveMachine.loadWorld("Saves/World.txt");
	display.InitializeWorld(world);
}

void Control::Loop()
{
	float deltaTime = 0.0f;
	sf::Clock clock;
	
	while (playing)
	{
		deltaTime = clock.restart().asSeconds();

		display.TickReset(player);

		game.Run(deltaTime, player, world);

		display.DrawTick(player, world);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			playing = false;
	}
	
	display.Close();
}

void Control::Save()
{
	saveMachine.savePlayer("Saves/Test.txt", this->player);
	saveMachine.saveWorld("Saves/World.txt", this->world);
}

void Control::Play()
{
	InitializePlayer();
	InitializeWorld();

	Loop();
	Save();
}
