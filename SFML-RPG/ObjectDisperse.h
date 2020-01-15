#pragma once
#include "WorldObject.h"
#include <vector>
#include <SFML\Graphics.hpp>

class ObjectDisperse
{
public:
	ObjectDisperse(WorldObject obj, sf::Vector2f range, float num);
	~ObjectDisperse();

	std::vector<WorldObject> Disperse(int nextID);

public:
	WorldObject objType;
	sf::Vector2f range;
	float popularity;
};

