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
	this->player = saveMachine.loadPlayer("Saves/Player.txt");
	display.InitializePlayer(player);
}

void Control::InitializeWorld()
{
	this->world = saveMachine.loadWorld("Saves/World.txt");
	display.InitializeWorld(world);
}

void Control::Loop()
{	
	while (playing)
	{
		display.TickReset(player);

		game.Run(player, world);

		display.DrawTick(player, world);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			playing = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			break;
	}
	if (!playing)
		display.Close();
	else
		Reload();
}

void Control::Reload()
{
	this->player = Player(
		"Player", -1, sf::Vector2f(100.0f, 100.0f),
		sf::IntRect(1, 1, 50, 50),
		100.0f, 100.0f
	);
	display.InitializePlayer(player);

	std::unordered_map<int, WorldObject> worldMap;
	std::unordered_set<int> collID;

	int ID = 0;
	WorldObject ironBox(
		"IronBox", 00, sf::Vector2f(0.0f, 0.0f),
		sf::IntRect(52, 52, 50, 50)
	);
	ObjectDisperse i(ironBox, sf::Vector2f(1000, 1000), 0.1f);
	ID = i.Disperse(ID, worldMap, collID);

	WorldObject box(
		"Box", 00, sf::Vector2f(0.0f, 0.0f),
		sf::IntRect(52, 1, 50, 50)
	);
	worldMap[0] = box;
	collID.insert(0);
	ObjectDisperse b(box, sf::Vector2f(1000, 1000), 0.5f);
	ID = b.Disperse(ID, worldMap, collID);

	this->world = World(sf::Vector2f(0.0f, 0.0f),
		sf::IntRect(1, 52, 50, 50), worldMap, collID);
	display.InitializeWorld(world);
}

void Control::Save()
{
	saveMachine.savePlayer("Saves/Player.txt", this->player);
	saveMachine.saveWorld("Saves/World.txt", this->world);
}

void Control::Play()
{
	InitializePlayer();
	InitializeWorld();

	Loop();
	Save();
}