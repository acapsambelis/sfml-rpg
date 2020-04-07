#include "World.h"
#include <SFML\Graphics.hpp>
#include <iostream>

World::World() :
	Displayable()
{
}

World::World(sf::IntRect rect,
	std::unordered_map<int, WorldObject> worldI,
	std::unordered_set<int> collID) :
	Displayable(rect, sf::Vector2f(0.0f, 0.0f))
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

