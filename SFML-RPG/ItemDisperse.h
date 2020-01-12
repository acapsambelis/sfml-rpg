#pragma once
#include "WorldObject.h"
#include <vector>
#include <SFML\Graphics.hpp>

class ItemDisperse
{
public:
	ItemDisperse(WorldObject obj, sf::Vector2f range, float num);
	~ItemDisperse();

	std::vector<WorldObject> Disperse(unsigned int nextID);

public:
	WorldObject objType;
	sf::Vector2f range;
	float popularity;
};

