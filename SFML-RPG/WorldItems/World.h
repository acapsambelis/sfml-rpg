#pragma once
#include <SFML\Graphics.hpp>
#include "Displayable.h"

#include "WorldObject.h"
#include <unordered_map>
#include <unordered_set>

class World : public Displayable
{
public:
	World();
	World(sf::IntRect rect,
		std::unordered_map<int, WorldObject> worldI,
		std::unordered_set<int> collID);
	~World();

	void SetObjSprite(sf::Texture& text);

public:
	std::unordered_map<int, WorldObject> worldItems;
	std::unordered_set<int> collID;
};

