#pragma once
#include <SFML\Graphics.hpp>
#include "..\..\Character\Player.h"
#include <vector>

class Gui
{
public:
	Gui();
	~Gui();

	void Initialize(sf::View guiView);

	void Draw(sf::RenderWindow& window);
	void Update(Player player);

private:
	
	const sf::Vector2f PIXELBUFFER = sf::Vector2f(20.0f, 20.0f);

	sf::View guiView;
	sf::RectangleShape healthbar;
};

