#pragma once
#include <SFML\Graphics.hpp>

#include "..\..\WorldItems\World.h"
#include "..\..\Character\Player.h"

#include <unordered_set>

class Game
{
public:
	Game();
	~Game();

	void Run(Player& player, World& world);
	void Collide(Player& player, World& world);

private:
	float deltaTime;
	sf::Clock clock;

};
