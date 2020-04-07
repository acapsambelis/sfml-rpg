#pragma once
#include <SFML\Graphics.hpp>

#include "..\..\WorldItems\World.h"
#include "..\..\Character\Player.h"

class Game
{
public:
	Game();
	~Game();

	void Run(float deltaTime, Player& player, World& world);
	void Collide(Player& player, World& world);

};
