#pragma once
#include <SFML\Graphics.hpp>
#include <map>


class World
{
public:
	World(sf::Texture* texture);
	~World();

	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape ground;

};

