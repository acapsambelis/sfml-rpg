#pragma once
#include <SFML\Graphics.hpp>
#include "WorldObject.h"
#include <vector>

class World
{
public:
	World(sf::Texture* texture, std::vector<WorldObject> &worldI);
	~World();

	void Draw(sf::RenderWindow& window);

public:
	std::vector<WorldObject>& worldItems;


private:
	sf::RectangleShape ground;

};

