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

#include "World.hpp"

namespace rpg {

	////////////////////////////////////////////////////////////
	World::World() :
		Displayable()
	{
	}

	////////////////////////////////////////////////////////////
	World::World(sf::Vector2f position, sf::IntRect texture_rect,
		std::unordered_map<int, Block> world_items,
		std::unordered_set<int> collision_ids) :
		Displayable(texture_rect, position)
	{
		this->world_items = world_items;
		this->collision_ids = collision_ids;
	}

	////////////////////////////////////////////////////////////
	World::~World()
	{
	}

	////////////////////////////////////////////////////////////
	void World::set_obj_sprite(sf::Texture& text)
	{
		for (unsigned int i = 0; i < world_items.size(); i++)
		{
			world_items[i].set_sprite(text);
		}
	}

	////////////////////////////////////////////////////////////
	std::string World::get_writeable()
	{
		std::string write = Displayable::GetWriteable();
		write += "\n-.";

		std::unordered_map<int, Block>::iterator it = world_items.begin();

		while (it != world_items.end())
		{
			if (it->second.get_name().compare(""))
			{
				write += "\n";
				write += it->second.get_writeable();
				write += "\n-";
			}
			it++;
		}
		write += ".\n";

		for (auto ID : collision_ids) {
			write += std::to_string(ID) + ',';
		}

		return write;
	}

} // namespace rpg
