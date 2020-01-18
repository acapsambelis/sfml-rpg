#pragma once
#include "WorldObject.h"
#include <vector>
#include <unordered_set>
#include <SFML\Graphics.hpp>

class ObjectDisperse
{
public:
	ObjectDisperse(WorldObject obj, sf::Vector2f range, float num);
	~ObjectDisperse();


	int Disperse(int nextID,
		std::unordered_set<WorldObject, MyHashFunction>& set,
		std::unordered_set<WorldObject, MyHashFunction>& set2);
	int Disperse(int nextID,
		std::unordered_set<WorldObject, MyHashFunction>& set);

public:
	WorldObject objType;
	sf::Vector2f range;
	float popularity;
};

