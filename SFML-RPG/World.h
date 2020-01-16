#pragma once
#include <SFML\Graphics.hpp>
#include "WorldObject.h"
#include <vector>
#include <unordered_set>

class World
{
public:
	World(sf::Texture* texture, std::unordered_set<WorldObject, MyHashFunction> &worldI,
		std::unordered_set<WorldObject, MyHashFunction>& coll);
	~World();

	void Draw(sf::RenderWindow& window);

public:
	std::unordered_set<WorldObject, MyHashFunction>& collideables;
	std::unordered_set<WorldObject, MyHashFunction>& worldItems;


private:
	sf::RectangleShape ground;

};

