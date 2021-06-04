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

#include "Control.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	Control::Control()
	{
		playing = true;
		new_world_gen = false;
	}

	////////////////////////////////////////////////////////////
	Control::~Control()
	{
	}

	////////////////////////////////////////////////////////////
	void Control::initialize_player()
	{
		this->player = Player("Player", -1, sf::Vector2f(100.0f, 100.0f),
			sf::IntRect(1, 1, 50, 50), 100.0f, 100.0f);
		display.initialize_player(player);
	}

	////////////////////////////////////////////////////////////
	void Control::initialize_world()
	{
		this->world = World(sf::Vector2f(0.0f, 0.0f), sf::IntRect(1, 52, 50, 50),
			std::unordered_map<int, Block>());
		display.initialize_world(world);
	}

	////////////////////////////////////////////////////////////
	void Control::loop()
	{
		while (playing)
		{
			display.tick_reset(player);

			game.update(player, world);

			display.draw_tick(player, world);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				playing = false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				new_world_gen = true;
				break;
			}

		}
	}

	////////////////////////////////////////////////////////////
	void Control::reload()
	{
		this->player = Player(
			"Player", -1, sf::Vector2f(100.0f, 100.0f),
			sf::IntRect(1, 1, 50, 50),
			100.0f, 100.0f
		);
		display.initialize_player(player);

		std::unordered_map<int, Block> worldMap;

		int ID = 0;
		Block ironBox(
			"IronBox", 00, sf::Vector2f(0.0f, 0.0f),
			sf::IntRect(52, 52, 50, 50)
		);
		Dispersal i(ironBox, sf::Vector2f(1000, 1000), 1.0f);
		ID = i.disperse(ID, worldMap);

		Block box(
			"Box", 00, sf::Vector2f(0.0f, 0.0f),
			sf::IntRect(52, 1, 50, 50)
		);
		Dispersal b(box, sf::Vector2f(1000, 1000), 0.5f);
		ID = b.disperse(ID, worldMap);

		this->world = World(sf::Vector2f(0.0f, 0.0f),
			sf::IntRect(1, 52, 50, 50), worldMap);
		display.initialize_world(world);
	}

	////////////////////////////////////////////////////////////
	void Control::save()
	{
		//save_machine.save_player("Saves/Player.arpg", this->player);
		//save_machine.save_world("Saves/World.arpg", this->world);
	}

	////////////////////////////////////////////////////////////
	void Control::play()
	{
		initialize_player();
		initialize_world();

		reload();

		while (playing)
		{
			loop();
			if (new_world_gen)
			{
				sf::sleep(sf::Time(sf::seconds(0.25f)));
				reload();
			}
		}
		display.close();
		save();
	}

} // namespace rpg
