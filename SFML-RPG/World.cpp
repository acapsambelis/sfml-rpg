#include "World.h"
#include <SFML\Graphics.hpp>

World::World(sf::Texture* texture, std::vector<WorldObject> &worldI,
	std::vector<WorldObject>& coll) :
	worldItems(worldI),
	collideables(coll)
{
	ground.setSize(sf::Vector2f(10000.0f, 10000.0f));
	ground.setOrigin(ground.getSize() / 2.0f);
	ground.setTexture(texture);
}

World::~World()
{
}

void World::Draw(sf::RenderWindow& window)
{
	window.draw(ground);
}

