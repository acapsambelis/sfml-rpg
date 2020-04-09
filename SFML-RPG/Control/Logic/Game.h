#pragma once

#include <unordered_set>

#include <SFML\Graphics.hpp>

#include "WorldItems\World.h"
#include "Character\Player.h"

namespace rpg {
	class Game
	{
	public:
		Game();
		~Game();

		void Run(Player& player, World& world);
		void Collide(Player& player, World& world);

		sf::Vector2f GetInput(Player& player);

	private:
		float deltaTime;
		sf::Clock clock;

	};
}