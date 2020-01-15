#include "Gui.h"
#include <iostream>

Gui::Gui(sf::RectangleShape& hth) :
	health(hth)
{
}

Gui::~Gui()
{
}

void Gui::Draw(sf::RenderWindow& window)
{
	for (unsigned int i = 0; i < elements.size(); ++i)
	{
		window.draw(elements[i]);
	}
}

void Gui::Update(Player ply)
{
	elements[0].setSize(sf::Vector2f(ply.health, 10.0f));
}
