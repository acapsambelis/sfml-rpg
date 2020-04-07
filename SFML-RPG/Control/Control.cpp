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

void Control::GenerateWorld()
{
	std::unordered_map<int, WorldObject> worldMap;
	std::unordered_set<int> collID;

	int ID = 0;
	// Grass
	WorldObject ironBox(
		/*Metadata*/ "IronBox", 00, sf::Vector2f(0.0f, 0.0f),
		/*Textures*/ sf::IntRect(52, 52, 50, 50)
	);
	ObjectDisperse i(ironBox, sf::Vector2f(1000, 1000), 0.1f);
	ID = i.Disperse(ID, worldMap, collID);

	// Stump
	WorldObject box(
		/*Metadata*/ "Box", 00, sf::Vector2f(0.0f, 0.0f),
		/*Textures*/ sf::IntRect(52, 1, 50, 50)
	);
	worldMap[0] = box;
	collID.insert(0);
	ObjectDisperse b(box, sf::Vector2f(1000, 1000), 0.5f);
	ID = b.Disperse(ID, worldMap, collID);

	this->world = World(sf::IntRect(1, 52, 50, 50), worldMap, collID);
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

void Control::Play()
{
	InitializePlayer();

	GenerateWorld();
	//InitializeWorld();

	Loop();
	saveMachine.savePlayer("Saves/Test.txt", this->player);
}
