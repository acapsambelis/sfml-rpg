#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <SFML\Graphics.hpp>

#include "WorldObject.h"

namespace rpg {
	class ObjectDisperse
	{
	public:
		ObjectDisperse(WorldObject obj, sf::Vector2f range, float num);
		~ObjectDisperse();

		int Disperse(int nextID,
			std::unordered_map<int, WorldObject>& map,
			std::unordered_set<int>& set);
		int Disperse(int nextID,
			std::unordered_map<int, WorldObject>& map);

	public:
		WorldObject objType;
		sf::Vector2f range;
		float popularity;
	};
}
