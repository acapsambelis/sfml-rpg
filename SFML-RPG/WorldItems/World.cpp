#include "World.h"
#include <SFML\Graphics.hpp>
#include <iostream>

World::World() :
	Displayable()
{
}

World::World(sf::Vector2f position, sf::IntRect rect,
	std::unordered_map<int, WorldObject> worldI,
	std::unordered_set<int> collID) :
	Displayable(rect, position)
{
	this->worldItems = worldI;
	this->collID = collID;
}

World::~World()
{
}

void World::SetObjSprite(sf::Texture& text)
{
	for (int i = 0; i < worldItems.size(); i++)
	{
		worldItems[i].SetSprite(text);
	}
}

std::string World::GetWriteable()
{
	std::string write = Displayable::GetWriteable();
	write += "\n-.";

	std::unordered_map<int, WorldObject>::iterator it = worldItems.begin();

	while (it != worldItems.end())
	{
		write += "\n";
		write += it->second.GetWriteable();
		write += "\n-";
		it++;
	}
	write += ".\n";

	for (auto ID : collID) {
		write += std::to_string(ID) + ',';
	}

	return write;
}

