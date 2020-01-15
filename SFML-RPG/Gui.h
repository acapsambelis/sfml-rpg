#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include <vector>

class Gui
{
public:
	Gui(sf::RectangleShape& hth);
	~Gui();

	void Draw(sf::RenderWindow& window);
	void Update(Player ply);

public:
	std::vector<sf::RectangleShape> elements;
	sf::RectangleShape& health;
};

