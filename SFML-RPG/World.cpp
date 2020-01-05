#include "World.h"
#include <SFML\Graphics.hpp>

World::World(sf::Texture* texture, std::vector<WorldObject> &worldI) :
	worldItems(worldI)
{
	ground.setSize(sf::Vector2f(10000.0f, 10000.0f));
	ground.setOrigin(ground.getSize() / 2.0f);
	ground.setTexture(texture);
	this->worldItems = worldI;
}

World::~World()
{
}

void World::Draw(sf::RenderWindow& window)
{
	window.draw(ground);
}

