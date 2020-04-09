////////////////////////////////////////////////////////////
//
// SFML-RPG - A top-down RPG demo
// 
// Author - Alex Capsambelis
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Game.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	Game::Game()
	{
		this->delta_time = 0.0f;
	}

	////////////////////////////////////////////////////////////
	Game::~Game()
	{
	}

	////////////////////////////////////////////////////////////
	void Game::update(Player& player, World& world)
	{
		this->delta_time = this->clock.restart().asSeconds();
		sf::Vector2f move = get_input(player);
		player.move(move.x, move.y);
		collide(player, world);
	}


	////////////////////////////////////////////////////////////
	void Game::collide(Player& player, World& world)
	{
		std::unordered_set<int> eraseIDs;
		for (auto id : world.getCollID())
		{
			bool mined = player.collide(world.get_world_item(id));
			if (mined)
			{
				eraseIDs.insert(id);
			}
		}
		for (int id : eraseIDs)
		{
			world.delete_world_item(id);
		}
	}

	////////////////////////////////////////////////////////////
	sf::Vector2f Game::get_input(Player& player)
	{
		sf::Vector2f movement(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.set_state(1);
			movement.x -= player.get_speed() * delta_time;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.set_state(1);
			movement.x += player.get_speed() * delta_time;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.set_state(1);
			movement.y -= player.get_speed() * delta_time;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.set_state(1);
			movement.y += player.get_speed() * delta_time;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			player.set_state(2);
		}

		return movement;
	}

} // namespace rpg
