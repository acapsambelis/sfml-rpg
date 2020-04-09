#include "Game.h"

namespace rpg {

	Game::Game()
	{
		this->deltaTime = 0.0f;
	}

	Game::~Game()
	{
	}

	void Game::Run(Player& player, World& world)
	{
		this->deltaTime = this->clock.restart().asSeconds();
		sf::Vector2f move = GetInput(player);
		player.Move(move.x, move.y);
		Collide(player, world);
	}


	void Game::Collide(Player& player, World& world)
	{
		std::unordered_set<int> eraseIDs;
		for (auto id : world.getCollID())
		{
			bool mined = player.Collide(world.getWorldItem(id));
			if (mined)
			{
				eraseIDs.insert(id);
			}
		}
		for (int id : eraseIDs)
		{
			world.DeleteWorldItem(id);
		}
	}

	sf::Vector2f Game::GetInput(Player& player)
	{
		sf::Vector2f movement(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.SetState(1);
			movement.x -= player.getSpeed() * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.SetState(1);
			movement.x += player.getSpeed() * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.SetState(1);
			movement.y -= player.getSpeed() * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.SetState(1);
			movement.y += player.getSpeed() * deltaTime;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			player.SetState(2);
		}

		return movement;
	}
}
