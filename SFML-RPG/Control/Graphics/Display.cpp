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

#include "Display.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	Display::Display()
	{
		// WINDOW //
		this->current_mode = sf::VideoMode::getDesktopMode();
		this->window.create(current_mode, "SFML-RPG", sf::Style::Fullscreen);

		// VIEWS //
		this->world_view = sf::View(sf::Vector2f(0.0f, 0.0f),
			sf::Vector2f(current_mode.width / 8.0f,
						 current_mode.height / 8.0f));
		this->gui_view = sf::View(sf::Vector2f(0.0f, 0.0f),
			sf::Vector2f(current_mode.width / 8.0f,
					     current_mode.height / 8.0f));

		// ATLAS //
		this->atlas = sf::Texture();
		atlas.loadFromFile("ImageRec/atlas.png");

		// GUI //
		this->gui.initialize(this->gui_view);
	}

	////////////////////////////////////////////////////////////
	Display::~Display()
	{
	}

	////////////////////////////////////////////////////////////
	void Display::initialize_player(Player& player)
	{
		player.set_sprite(atlas);
	}

	////////////////////////////////////////////////////////////
	void Display::initialize_world(World& world)
	{
		world.set_sprite(atlas);
		world.set_scale(1000.0f, 1000.0f);
		world.set_obj_sprite(atlas);
	}

	////////////////////////////////////////////////////////////
	void Display::tick_reset(Player player)
	{
		window.clear(sf::Color(150, 150, 150));
		world_view.setCenter(player.get_position());
		window.setView(world_view);
	}

	////////////////////////////////////////////////////////////
	void Display::draw_tick(Player player, World world)
	{
		// Draw the world, force since it is larger than view
		world.draw(window, true);
		for (unsigned int i = 0; i < world.world_items.size(); i++)
		{
			world.world_items[i].draw(window, world_view);
		}
		player.draw(window, world_view);

		gui.update(player);
		window.setView(gui_view);
		gui.draw(window);

		window.display();
	}

	////////////////////////////////////////////////////////////
	void Display::close()
	{
		window.close();
	}

} // namespace rpg
